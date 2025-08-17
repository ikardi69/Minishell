/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strc_cr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:14:48 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 19:10:26 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

void	append_arg(t_ptr **head, char ***args, char *word)
{
	int		count;
	char	**new_args;
	int		i;

	count = 0;
	if (*args)
		while ((*args)[count])
			count++;
	new_args = ft_mall(head, (sizeof(char *) * (count + 2)));
	i = 0;
	while (i < count)
	{
		new_args[i] = (*args)[i];
		i++;
	}
	new_args[count] = ft_strdup1(head, word);
	new_args[count + 1] = NULL;
	*args = new_args;
}

static t_cmd	*handle_new_command(t_ptr **head,
		t_cmd **cmd_list, t_cmd **curr_cmd)
{
	*curr_cmd = init_new_cmd(head);
	if (*cmd_list == NULL)
		*cmd_list = *curr_cmd;
	return (*curr_cmd);
}

static void	handle_pipe_token(t_ptr **head, t_cmd **curr_cmd)
{
	(*curr_cmd)->next = init_new_cmd(head);
	*curr_cmd = (*curr_cmd)->next;
}

static void	handle_redirection(t_ptr **head, t_cmd *curr_cmd,
		t_tkn **current_token)
{
	t_redirs	*redir;

	redir = ft_mall(head, sizeof(t_redirs));
	redir->type = (*current_token)->tkn_typ;
	if ((*current_token)->next && (*current_token)->next->tkn_typ == wrd)
	{
		redir->filename = ft_strdup1(head, (*current_token)->next->vl);
		*current_token = (*current_token)->next;
	}
	else
		redir->filename = ft_strdup1(head, "");
	redir->next = NULL;
	append_redir(&(curr_cmd->redirs), redir);
}

t_cmd	*parse_tokens_to_commands(t_ptr **head, t_tkn *tokens)
{
	t_cmd	*cmd_list;
	t_cmd	*curr_cmd;
	t_tkn	*current_token;

	cmd_list = NULL;
	curr_cmd = NULL;
	current_token = tokens;
	while (current_token)
	{
		if (curr_cmd == NULL)
			handle_new_command(head, &cmd_list, &curr_cmd);
		if (current_token->tkn_typ == PI)
			handle_pipe_token(head, &curr_cmd);
		else if (current_token->tkn_typ >= red_in
			&& current_token->tkn_typ <= HEREDOC)
			handle_redirection(head, curr_cmd, &current_token);
		else if (current_token->tkn_typ == wrd)
			append_arg(head, &(curr_cmd->args), current_token->vl);
		current_token = current_token->next;
	}
	return (cmd_list);
}
