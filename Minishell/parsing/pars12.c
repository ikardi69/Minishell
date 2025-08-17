/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:57:42 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 19:08:48 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

static char	*handle_env_value(t_ptr **head_ptr, t_env_copy *env_node)
{
	char	*str;

	if (env_node->value)
		str = ft_strdup1(head_ptr, env_node->value);
	else
		str = ft_strdup1(head_ptr, "");
	return (str);
}

char	*get_vr(t_env_copy **head, t_ptr **head_ptr, char *name)
{
	t_env_copy	*tmp;
	size_t		name_len;

	if (!head || !*head || !name)
		return (NULL);
	tmp = *head;
	name_len = ft_strlen(name);
	while (tmp)
	{
		if (tmp->key && !(ft_strcmp_vr(tmp->key, name, name_len)))
			return (handle_env_value(head_ptr, tmp));
		tmp = tmp->next;
	}
	return (NULL);
}

t_cmd	*init_new_cmd(t_ptr **head)
{
	t_cmd	*cmd;

	cmd = ft_mall(head, sizeof(t_cmd));
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	append_redir(t_redirs **list, t_redirs *new_redir)
{
	t_redirs	*tmp;

	if (!*list)
		*list = new_redir;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_redir;
	}
}
