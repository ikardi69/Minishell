/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pcollector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:58:14 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/13 15:24:15 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

void	*ft_mall(t_ptr **head, ssize_t size)
{
	void	*new_ptr;

	if (size <= 0)
	{
		ft_lstclear1(head, free);
		if (size == -1)
			return (NULL);
		exit(1);
	}
	new_ptr = (void *)malloc(size);
	if (!new_ptr)
	{
		ft_lstclear1(head, free);
		exit(1);
	}
	add_node(head, new_ptr);
	return (new_ptr);
}

void	ft_lstadd_back1(t_ptr **lst, t_ptr *new)
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

void	ft_lstadd_back_tkn(t_tkn **lst, t_tkn *new)
{
	t_tkn	*tmp;

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

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*tmp;

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

void	ft_lstclear1(t_ptr **lst, void (*del)(void*))
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
