/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:42:27 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/17 18:58:54 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

static void	handle_error_case(int *pos)
{
	(*pos) += 1;
}

static char	*read_pid_file(t_ptr **head)
{
	int		fd;
	ssize_t	bytes;
	char	buf[128];

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1)
		return (NULL);
	bytes = read(fd, buf, sizeof(buf) - 1);
	close(fd);
	if (bytes <= 0)
		return (NULL);
	buf[bytes] = '\0';
	return (ft_strdup1(head, buf));
}

static char	*extract_pid(t_ptr **head, char *buf)
{
	int		i;
	int		j;
	char	*pid_str;

	i = 0;
	while (buf[i] && buf[i] != ' ')
		i++;
	pid_str = ft_mall(head, (i + 1));
	if (!pid_str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		pid_str[j] = buf[j];
		j++;
	}
	pid_str[i] = '\0';
	return (pid_str);
}

void	get_shell_pid_str(t_ptr **head, int *pos)
{
	char	*buf;
	char	*pid_str;

	buf = read_pid_file(head);
	if (!buf)
	{
		handle_error_case(pos);
		return ;
	}
	pid_str = extract_pid(head, buf);
	if (!pid_str)
	{
		handle_error_case(pos);
		return ;
	}
	(*pos) += 1;
	ft_putstr_fd(pid_str, 1);
	ft_putstr_fd(": command not found\n", 1);
}

t_env	*set_env_ls(t_ptr **head_ptr, char **env)
{
	t_env	*set;
	int		i;

	if (!env || !*env)
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
