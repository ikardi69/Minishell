/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:09:53 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/21 15:05:41 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void cpy(char *vl, char *input, int pos, int len)
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

int	splt_quoted(t_ptr **head, t_tkn **token, char *input, int *i)
{
	int			len;
	char		*vl;
	int			pos;
	char		q_type;

	if (!input)
		return (ft_mall(head, 0), 0);
	q_type = input[*i];
	(*i)++;
	len = 0;
	pos = *i;
	while (input[*i] && input[*i] != q_type)
	{
		(*i)++;
		len++;
	}
	if (input[*i] == q_type)
		(*i)++;  // Skip closing quote
	else
		return (0);  // Unclosed quote
	vl = ft_mall(head, (len + 1));
	cpy(vl, input, pos, len);
	creat_tkn_node(head, token, vl, wrd);
	return (0);
}
