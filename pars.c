/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:39:06 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/20 22:04:37 by mteffahi         ###   ########.fr       */
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
			cnt++;
	}
	if (cnt == 2)
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

void	first_q(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"' || input[i] == '(')
		{
			if (!(check_q(input, i)))
			{
				ft_putstr_fd("Syntax error\n", 2);
				return ;
			}
		}
	}
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

t_tkn_type identify_tkn(char *val)
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


int	splt(t_ptr **head, t_tkn **token, char *input, int *i)
{
	int			len;
	char		*vl;
	int			pos;
	t_tkn_type	type;

	if (!input)
		return (ft_mall(head, 0), 0);
	len = 0;
	pos = *i;
	while (input[*i] && input[*i] != ' ')
	{
		(*i)++;
		len++;
	}
	vl = ft_mall(head, (len + 1));
	len = -1;
	while (pos < *i)
	{
		vl[++len] = input[pos];
		pos++;
	}
	vl[len + 1] = '\0';
	type = identify_tkn(vl);
	creat_tkn_node(head, token, vl, type);
	return (0);
}

static void	printi_zab(t_tkn **head)
{
	t_tkn	*tmp;
	int		i;

	i = 0;
	tmp = *head;
	while (tmp && tmp->next)
	{
		printf("token value %s , token type %d, token index %d\n", tmp->vl, tmp->tkn_typ, i);
		i++;
		tmp = tmp->next;
	}
}

void	pars(t_ptr **head,char *input)
{
	// char	*cmd;
	int		i;
	t_tkn	*tkn_head;

	tkn_head = NULL;
	// tkn_head = ft_mall(head, sizeof(t_tkn));
	// tkn_head->next = NULL;
	// tkn_head->vl = NULL;
	// cmd = ft_strdup(head, input);
	// free(input);
	if (!input)
		return ;
	first_q(input);
	invalid_sqnc(input);
	i = 0;
	// while (cmd[i])
	// {
	// 	if (i == 0)
	// 		splt(head, &tkn_head, cmd, &i);
	// 	else if (cmd[i] == '\'' || cmd[i] == '\"')
	// 		splt_quoted(head, &tkn_head, cmd, &i);
	// 	else if (cmd[i] == ' ')
	// 		splt(head, &tkn_head, cmd, &i);
	// 	else
	// 		i++;
	// }
	while (input[i])
	{
		if (i == 0 || input[i] == ' ')
		{
			if (input[i] == ' ')
				i++;  // Skip the space
			if (input[i])  // Check if we're not at the end
				splt(head, &tkn_head, input, &i);
		}
		else if (input[i] == '\'' || input[i] == '\"')
			splt_quoted(head, &tkn_head, input, &i);
		else
			i++;
	}
	printi_zab(&tkn_head);
}
