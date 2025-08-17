/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:15:19 by ilallali          #+#    #+#             */
/*   Updated: 2025/08/17 22:40:04 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

static int	parse_assign(char *arg, char **key, char **value)
{
	char	*op_pos;
	int		op_type;

	op_type = 1;
	op_pos = ft_strchr(arg, '+');
	if (op_pos && op_pos[1] == '=')
		op_type = 2;
	else
		op_pos = ft_strchr(arg, '=');
	if (op_pos == NULL)
	{
		*key = ft_strdup(arg);
		*value = NULL;
		return (0);
	}
	*value = ft_strdup(op_pos + op_type);
	*op_pos = '\0';
	*key = ft_strdup(arg);
	if (op_type == 2)
		op_pos[0] = '+';
	else
		op_pos[0] = '=';
	return (op_type);
}

static void	append_to_env(t_shell *shell, char *key, char *value)
{
	char	*old_value;
	char	*new_value;

	old_value = get_env_value(*(shell->env_list), key);
	if (old_value)
	{
		new_value = ft_strjoin(old_value, value);
		set_env_value(shell->env_list, key, new_value);
		free(new_value);
	}
	else
		set_env_value(shell->env_list, key, value);
}

static void	process_export_arg(char *arg, t_shell *shell)
{
	char	*key;
	char	*value;
	int		assign_type;

	assign_type = parse_assign(arg, &key, &value);
	if (!is_valid_identifier(key))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	else
	{
		if (assign_type == 2)
			append_to_env(shell, key, value);
		else
			set_env_value(shell->env_list, key, value);
	}
	free(key);
	if (value)
		free(value);
}

static int	process_and_advance(t_cmd *command, t_shell *shell, int i)
{
	char	*full_arg;
	char	*current_arg;

	current_arg = command->args[i];
	if (current_arg[ft_strlen(current_arg) - 1] == '='
		&& command->args[i + 1])
	{
		full_arg = ft_strjoin(current_arg, command->args[i + 1]);
		if (!full_arg)
			return (-1);
		process_export_arg(full_arg, shell);
		free(full_arg);
		return (2);
	}
	else
	{
		process_export_arg(current_arg, shell);
		return (1);
	}
}

int	exec_export(t_cmd *command, t_shell *shell)
{
	int	i;
	int	consumed;

	i = 1;
	if (!command->args[i])
		return (print_export_format(shell));
	while (command->args[i])
	{
		consumed = process_and_advance(command, shell, i);
		if (consumed == -1)
			return (1);
		i += consumed;
	}
	return (0);
}
