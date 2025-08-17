/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 18:10:00 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9') || c == '_')
		return (1);
	else
		return (0);
}

int	chek_equal(char *vl)
{
	int	i;

	i = -1;
	while (vl[++i])
	{
		if (vl[i] == '=')
			return (1);
	}
	return (0);
}

void	set_node(t_env **head, t_ptr **ptr_head, char *env_val)
{
	t_env	*node;

	node = ft_mall(ptr_head, sizeof(t_env));
	node->var = ft_strdup1(ptr_head, env_val);
	if (!node->var)
	{
		ft_mall(ptr_head, 0);
		return ;
	}
	node->next = NULL;
	ft_lstadd_back_env(head, node);
}

static char	*gt_env_val(t_ptr **ptr_head, t_env_copy *env_node)
{
	char	*value;

	if (env_node->value)
		value = ft_mall(ptr_head, ft_strlen(env_node->value) + 1);
	else
		value = ft_mall(ptr_head, 1);
	if (!value)
		return (NULL);
	if (env_node->value)
		ft_strcpy(value, env_node->value);
	else
		value[0] = '\0';
	return (value);
}

char	*extract_vl(t_ptr **ptr_head, t_env_copy **env_head, char *var_name)
{
	t_env_copy	*tmp;
	size_t		name_len;

	if (!var_name || !env_head || !*env_head)
		return (NULL);
	tmp = *env_head;
	name_len = ft_strlen(var_name);
	while (tmp)
	{
		if (tmp->key && !(ft_strcmp_vr(tmp->key, var_name, name_len)))
			return (gt_env_val(ptr_head, tmp));
		tmp = tmp->next;
	}
	return (NULL);
}
