/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pcollector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:58:14 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/09 18:10:18 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ptr	*add_node(void *ptr)
{
	t_ptr	*new_node;

	new_node = (t_ptr *)malloc(sizeof(t_ptr));
	if (!new_node)
		return NULL;
	new_node->ptr = ptr;
	new_node->next = NULL;
	return (new_node);
}

void    *ft_mall(t_ptr **head, ssize_t size)
{
	void    *new_ptr;
	t_ptr	*new_node;

	if (size <= 0)
		return (ft_lstclear(head, free), NULL);
	new_ptr = (void *)malloc(size);
	if (!new_ptr)
		return (ft_lstclear(head, free), NULL);
	new_node = add_node(new_ptr);
	if (!new_node)
		return (ft_lstclear(head, free), NULL);
	ft_lstadd_back(head, new_node);
	return (new_ptr);
}

void	ft_lstadd_back(t_ptr **lst, t_ptr *new)
{
	t_ptr	*tmp;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstclear(t_ptr **lst, void (*del)(void*))
{
	t_ptr	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->ptr);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
