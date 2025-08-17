/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:19:04 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 18:45:09 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

int	splt(t_ptr **head, t_tkn **token, char *input, int *i)
{
	int		len;
	char	*vl;
	int		pos;

	if (!input)
		return (ft_mall(head, 0), 0);
	len = 0;
	pos = *i;
	len = calculate_token_length(input, i);
	if (input[*i] == '$')
		return (1);
	vl = extract_token_value(head, input, pos, len);
	create_and_add_token(head, token, vl);
	return (0);
}

int	calculate_token_length(char *input, int *i)
{
	int	len;

	len = 0;
	while (input[*i] && input[*i] != ' '
		&& input[*i] != '\'' && input[*i] != '"'
		&& input[*i] != '|' && input[*i] != '<'
		&& input[*i] != '>' && input[*i] != '$')
	{
		(*i)++;
		len++;
	}
	return (len);
}

char	*extract_token_value(t_ptr **head, char *input, int pos, int len)
{
	char	*vl;
	int		idx;

	vl = ft_mall(head, (len + 1));
	idx = 0;
	while (pos < (pos + len))
	{
		vl[idx] = input[pos];
		pos++;
		idx++;
		if (idx >= len)
			break ;
	}
	vl[len] = '\0';
	return (vl);
}

void	create_and_add_token(t_ptr **head, t_tkn **token, char *vl)
{
	t_tkn_type	type;

	type = identify_tkn(vl);
	creat_tkn_node(head, token, vl, type);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		ft_putnbr(nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		write(1, &(char){nbr + '0'}, 1);
}
