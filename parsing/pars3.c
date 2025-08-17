/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:09:53 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 18:02:45 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

void	cpy(char *vl, char *input, int pos, int len)
{
	int	tmp;

	tmp = 0;
	while (tmp < len)
	{
		vl[tmp] = input[pos + tmp];
		tmp++;
	}
	vl[tmp] = '\0';
}

static char	*exp_var(
	t_parse_ctx *ctx, char *name)
{
	char	*var_val;
	char	*tmp;

	if (name[0] == '\0')
	{
		tmp = ft_mall(ctx->head, 2);
		tmp[0] = '$';
		tmp[1] = '\0';
		return (tmp);
	}
	if (name[0] == '?' && name[1] == '\0')
		return (ft_itoa1(ctx->head, ctx->shell->last_exit_status));
	var_val = get_vr(ctx->shell->env_list, ctx->head, name);
	if (!var_val)
	{
		var_val = ft_mall(ctx->head, 1);
		var_val[0] = '\0';
	}
	return (var_val);
}

static char	*handle_dollar(
	t_parse_ctx *ctx, char *result, int *start)
{
	char	*tmp;
	char	*name;
	char	*val;

	if (*ctx->i > *start)
	{
		tmp = ft_mall(ctx->head, (*ctx->i - *start) + 1);
		cpy(tmp, ctx->input, *start, *ctx->i - *start);
		result = ft_strjoin1(ctx->head, result, tmp);
	}
	(*ctx->i)++;
	name = gt_nm(ctx->input, ctx->i, ctx->head);
	val = exp_var(ctx, name);
	result = ft_strjoin1(ctx->head, result, val);
	*start = *ctx->i;
	return (result);
}

static char	*process_inside_quotes(
	t_parse_ctx *ctx, char *result, char q_type, int start)
{
	char	*tmp;

	while (ctx->input[*ctx->i] && ctx->input[*ctx->i] != q_type)
	{
		if (ctx->input[*ctx->i] == '$' && q_type == '\"')
			result = handle_dollar(ctx, result, &start);
		else
			(*ctx->i)++;
	}
	if (*ctx->i > start)
	{
		tmp = ft_mall(ctx->head, (*ctx->i - start) + 1);
		cpy(tmp, ctx->input, start, *ctx->i - start);
		result = ft_strjoin1(ctx->head, result, tmp);
	}
	return (result);
}

int	splt_quoted(t_parse_ctx *ctx)
{
	char	q_type;
	char	*result;

	if (!ctx->input)
		return (ft_mall(ctx->head, 0), 0);
	q_type = ctx->input[*ctx->i];
	(*ctx->i)++;
	result = ft_mall(ctx->head, 1);
	result[0] = '\0';
	result = process_inside_quotes(ctx, result, q_type, *ctx->i);
	if (ctx->input[*ctx->i] == q_type)
		(*ctx->i)++;
	creat_tkn_node(ctx->head, ctx->tkn_head,
		result, identify_tkn(result));
	return (0);
}
