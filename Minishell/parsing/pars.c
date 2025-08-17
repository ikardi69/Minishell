/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:39:06 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 17:09:17 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

// static void	printi_zab(t_tkn **head)
// {
// 	t_tkn	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = *head;
// 	while (tmp)
// 	{
// 		printf("token value %s , token type %d, token index %d\n"
//				, tmp->vl, tmp->tkn_typ, i);
// 		i++;
// 		tmp = tmp->next;
// 	}
// }

// Handle shell PID case
int	handle_shell_pid(t_ptr **head, int *i)
{
	get_shell_pid_str(head, i);
	return (0);
}

// Process individual characters in the input
int	process_char_at_index(t_shell *shell, t_parse_ctx *ctx)
{
	if (ctx->input[*ctx->i] && ctx->input[*ctx->i] == ' ')
		(*ctx->i)++;
	else if (ctx->input[*ctx->i]
		&& (ctx->input[*ctx->i] == '\'' || ctx->input[*ctx->i] == '"'))
		splt_quoted(ctx);		//splt_quoted(ctx->head, ctx->tkn_head, ctx->input, ctx->i);
	else if (ctx->input[*ctx->i]
		&& (ctx->input[*ctx->i] == '|' || ctx->input[*ctx->i] == '<'
			|| ctx->input[*ctx->i] == '>'))
		handle_rdr(ctx->head, ctx->tkn_head, ctx->input, ctx->i);
	else if (ctx->input[*ctx->i]
		&& (ctx->input[*ctx->i] == '$' && ctx->input[*ctx->i + 1] == '$'))
		return (handle_shell_pid(ctx->head, ctx->i));
	else if (ctx->input[*ctx->i] == '$' && ctx->input[*ctx->i + 1] == '?')
		shell_last_exit(ctx->input, ctx->i, shell->last_exit_status);
	else if (ctx->input[*ctx->i] && ctx->input[*ctx->i] == '$')
		handle_variable_expansion(shell, ctx);
	else if (ctx->input[*ctx->i])
		splt(ctx->head, ctx->tkn_head, ctx->input, ctx->i);
	return (1);
}

// Helper function to handle the main tokenization loop
int	tokenize_input(t_shell *shell, t_ptr **head, char *input, t_tkn **tkn_head)
{
	t_parse_ctx	ctx;
	int			i;

	i = 0;
	ctx.shell = shell;
	ctx.head = head;
	ctx.input = input;
	ctx.i = &i;
	ctx.tkn_head = tkn_head;
	while (input[i])
	{
		if (!process_char_at_index(shell, &ctx))
			return (0);
	}
	return (1);
}

// Handle variable expansion
void	handle_variable_expansion(t_shell *shell, t_parse_ctx *ctx)
{
	char	*whole_vr;

	(*ctx->i)++;
	whole_vr = get_vr(shell->env_list, ctx->head,
			gt_nm(ctx->input, ctx->i, ctx->head));
	creat_tkn_node(ctx->head, ctx->tkn_head, whole_vr, identify_tkn(whole_vr));
}

// Main parsing function - now using t_shell struct (3 parameters instead of 4)
t_cmd	*pars(t_shell *shell, t_ptr **head, char *inp)
{
	t_tkn	*tkn_head;
	t_cmd	*final_cmd_list;
	char	*input;

	tkn_head = NULL;
	final_cmd_list = NULL;
	input = cpy_input(head, inp);
	if (!input || !first_q(input) || !invalid_sqnc(input))
		return (NULL);
	if (!tokenize_input(shell, head, input, &tkn_head))
		return (NULL);
	if (!last_pipe_check(&tkn_head))
		return (NULL);
	final_cmd_list = parse_tokens_to_commands(head, tkn_head);
	return (final_cmd_list);
}
