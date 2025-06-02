/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/06/02 13:52:13 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	node->var = ft_strdup(ptr_head, env_val);
	if (!node->var)
	{
		ft_mall(ptr_head, 0);
		return ;
	}
	node->next = NULL;
	ft_lstadd_back_env(head, node);
}

t_env	*set_env_ls(t_ptr **head_ptr, char **env)
{
	t_env	*set;
	int		i;

	if (!*env)
		return (NULL);
	set = NULL;
	i = 0;
	while (env[i])
	{
		set_node(&set, head_ptr, env[i]);
		i++;
	}
	return (set);
}

// void	handl_var_name(t_ptr **head, t_tkn **tkns)
// {
// 	t_tkn	*tmp;

// 	tmp = *tkns;
// 	while (tmp)
// 	{
// 		if (chek_equal(tmp->vl))
// 	}
	
// }
