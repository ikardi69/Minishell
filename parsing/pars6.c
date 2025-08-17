/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:14:45 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 22:56:10 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

void	shell_last_exit(char *input, int *i, int shell_last_exit)
{
	ft_putnbr(shell_last_exit);
	if (ft_strlen(input) == 2 && input[0] == '$' && input[1] == '?')
		ft_putchar_fd('\n', 1);
	(*i) += 2;
}

int	little_check(char *input)
{
	if (input[0] == '\"' && input[1] == '\"')
		return (0);
	else
		return (1);
}

static int	count_non_whitespace(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (!(input[i] >= 9 && input[i] <= 13))
			count++;
		i++;
	}
	return (count);
}

char	*cpy_input(t_ptr **head, char *input)
{
	char	*result;
	int		i;
	int		j;

	result = ft_mall(head, count_non_whitespace(input) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (!(input[i] >= 9 && input[i] <= 13))
		{
			result[j] = input[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	last_pipe_check(t_tkn **head)
{
	t_tkn	*tmp;

	if (!*head)
		return (0);
	tmp = *head;
	while (tmp)
	{
		if (tmp->tkn_typ == 2)
		{
			if (tmp->next && tmp->next->tkn_typ == 2)
				return (ft_putstr_fd("syntax error near unexpected token `|'\n",
						1), 0);
		}
		tmp = tmp->next;
	}
	return (1);
}
