/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:23:59 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/15 15:28:09 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

void	add_node(t_ptr **head, void *ptr)
{
	t_ptr	*new_node;

	new_node = (t_ptr *)malloc(sizeof(t_ptr));
	if (!new_node)
		ft_mall(head, -1);
	if (!ptr)
	{
		new_node->ptr = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->ptr = ptr;
		new_node->next = NULL;
	}
	ft_lstadd_back1(head, new_node);
}

// int	is_after_equals(char *input, int i)
// {
// 	if (i == 0)
// 		return (0);
// 	if (i > 0 && input[i - 1] == '=')
// 		return (1);
// 	return (0);
// }

// int splt_after_equals(t_ptr **head, t_tkn **token, char *input, int *i)
// {
//     int start = *i;

//     // Move backwards to include variable name before '='
//     while (start > 0 && input[start - 1] != ' ' && input[start - 1] != '\t')
//         start--;

//     // Move forward from '=' to capture full value
//     (*i)++; // move past '='

//     if (input[*i] == '\'' || input[*i] == '"')
//     {
//         char quote = input[*i];
//         (*i)++;
//         while (input[*i] && input[*i] != quote)
//             (*i)++;
//         if (input[*i] == quote)
//             (*i)++;
//     }
//     else
//     {
//         while (input[*i] && input[*i] != ' ' && input[*i] != '\t')
//             (*i)++;
//     }

//     // Copy the full "var=value" including quotes if they exist
//     char *vl = ft_mall(head, (*i - start) + 1);
//     cpy(vl, input, start, (*i - start));
//     creat_tkn_node(head, token, vl, identify_tkn(vl));

//     return 0;
// }

