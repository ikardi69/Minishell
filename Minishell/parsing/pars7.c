/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:16:54 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/13 15:17:14 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

int	checker_synx(char *input, char check)
{
	int	cnt;
	int	i;

	i = -1;
	cnt = 0;
	while (input[++i])
	{
		if (input[i] == check)
			cnt++;
	}
	if (cnt > 0 && cnt % 2 == 0)
		return (1);
	else
		return (0);
}

static int	check_q_helper(char *input, int i)
{
	while (input[i])
	{
		if (input[i] == ')')
			return (1);
		i++;
	}
	return (0);
}

int	check_q(char *input, int i)
{
	if (input[i] == '\'')
		return (checker_synx(input, '\''));
	else if (input[i] == '"')
		return (checker_synx(input, '"'));
	else if (input[i] == '(')
		return (check_q_helper(input, i));
	return (57);
}

int	first_q(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"' || input[i] == '(')
		{
			if (!(check_q(input, i)))
				return (ft_putstr_fd("Syntax error\n", 2), 0);
		}
	}
	return (1);
}

void	creat_tkn_node(t_ptr **head, t_tkn **tkn_head, char *val, t_tkn_type type)
{
	t_tkn	*node;

	node = ft_mall(head, sizeof(t_tkn));
	node->vl = val;
	node->tkn_typ = type;
	node->next = NULL;
	ft_lstadd_back_tkn(tkn_head, node);
}
