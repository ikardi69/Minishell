/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:57:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 18:10:22 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

t_tkn_type	identify_tkn(char *val)
{
	if (!val || !*val)
		return (NULL_Tk);
	else if (ft_strcmp(val, "|") == 0)
		return (PI);
	else if (ft_strcmp(val, ">") == 0)
		return (red_out);
	else if (ft_strcmp(val, "<") == 0)
		return (red_in);
	else if (ft_strcmp(val, ">>") == 0)
		return (red_apnd);
	else if (ft_strcmp(val, "<<") == 0)
		return (HEREDOC);
	else
		return (wrd);
}

// Main redirection handler - now simplified
int	handle_rdr(t_ptr **head, t_tkn **token, char *input, int *i)
{
	if (input[*i] == '|')
		handle_pipe(head, token, i);
	else if (input[*i] == '<')
		handle_input_rdr(head, token, input, i);
	else if (input[*i] == '>')
		handle_output_rdr(head, token, input, i);
	return (0);
}

// Handle pipe character
void	handle_pipe(t_ptr **head, t_tkn **token, int *i)
{
	char		*vl;
	t_tkn_type	type;

	vl = ft_mall(head, 2);
	vl[0] = '|';
	vl[1] = '\0';
	(*i)++;
	type = identify_tkn(vl);
	creat_tkn_node(head, token, vl, type);
}

// Handle input redirection (< and <<)
void	handle_input_rdr(t_ptr **head, t_tkn **token, char *input, int *i)
{
	char		*vl;
	t_tkn_type	type;

	if (input[*i + 1] == '<')
	{
		vl = ft_mall(head, 3);
		vl[0] = '<';
		vl[1] = '<';
		vl[2] = '\0';
		(*i) += 2;
	}
	else
	{
		vl = ft_mall(head, 2);
		vl[0] = '<';
		vl[1] = '\0';
		(*i)++;
	}
	type = identify_tkn(vl);
	creat_tkn_node(head, token, vl, type);
}

// Handle output redirection (> and >>)
void	handle_output_rdr(t_ptr **head, t_tkn **token, char *input, int *i)
{
	char		*vl;
	t_tkn_type	type;

	if (input[*i + 1] == '>')
	{
		vl = ft_mall(head, 3);
		vl[0] = '>';
		vl[1] = '>';
		vl[2] = '\0';
		(*i) += 2;
	}
	else
	{
		vl = ft_mall(head, 2);
		vl[0] = '>';
		vl[1] = '\0';
		(*i)++;
	}
	type = identify_tkn(vl);
	creat_tkn_node(head, token, vl, type);
}
