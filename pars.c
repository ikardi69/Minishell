/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:39:06 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/14 17:14:28 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checker_synx(char *input, char check)
{
	int	cnt;
	int	i;

	i = -1;
	cnt = 0;
	while (input[++i])
	{
		if (input[i] == check)
		{
			printf("input[i] = %c\n", input[i]);
			cnt++;
		}
	}
	printf("cnt = %d\n", cnt);
	if (cnt == 2)
		return (1);
	else
		return (0);
}

int	check_q(char *input, int i)
{
	if (input[i] == '\'')
		return (checker_synx(input, '\''));
	else if (input[i] == '"')
		return (checker_synx(input, '"'));
	else if (input[i] == '(')
		return (checker_synx(input, '('));
	return (57);
}

void	first_q(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"' || input[i] == '(')
		{
			if (!(check_q(input, i)))
				perror("syntax kda\n");
		}
	}
}

void	pars(char *input)
{
	first_q(input);
}
