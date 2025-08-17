/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:23:59 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/15 17:44:26 by mteffahi         ###   ########.fr       */
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

void	*ft_memcpy1(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dptr = (unsigned char *)dest;
	sptr = (const unsigned char *)src;
	if (dptr == sptr)
		return (dptr);
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup1(t_ptr **head, const char *s)
{
	size_t	size;
	char	*result;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	result = ft_mall(head, size);
	if (!result)
		return (NULL);
	ft_memcpy1(result, s, ft_strlen(s));
	result[ft_strlen(s)] = '\0';
	return (result);
}

char	*ft_strjoin1(t_ptr **head, char const *s1, char const *s2)
{
	char	*result;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup1(head, ""));
	if (s1[0] == '\0')
		return (ft_strdup1(head, s2));
	if (s2[0] == '\0')
		return (ft_strdup1(head, s1));
	size = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	result = ft_mall(head, size);
	if (!result)
		return (NULL);
	ft_memcpy1(result, s1, ft_strlen(s1));
	ft_memcpy1(result + ft_strlen(s1), s2, ft_strlen(s2));
	result[size - 1] = '\0';
	return (result);
}
