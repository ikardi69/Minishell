/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strc_cr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:14:48 by mteffahi          #+#    #+#             */
/*   Updated: 2025/07/04 19:37:13 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*crt_cmd(t_ptr **ptr)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = ft_mall(ptr, sizeof(t_cmd));
	cmd->args = NULL;
	cmd->post_redirs = NULL;
	cmd->pre_redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*parse_tokens_to_commands(t_tkn *tokens);