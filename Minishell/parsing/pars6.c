/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:14:45 by mteffahi          #+#    #+#             */
/*   Updated: 2025/08/13 15:15:29 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/exec.h"

void shell_last_exit(char *input,int *i, int shell_last_exit)
{
	ft_putnbr(shell_last_exit);
	if (ft_strlen(input) == 2 && input[0] == '$' && input[1] == '?')
		ft_putchar_fd('\n', 1);
	(*i) += 2;
}

int little_check(char *input)
{
	if (input[0] == '\"' && input[1] == '\"')
		return (0);
	else
		return (1);
}

char *cpy_input(t_ptr **head, char *input)
{
    int total_len = 0;
    int non_whitespace_count = 0;
    int i, j;
    char *result;// echo	hi
    
    while (input[total_len])
    {
        if (!(input[total_len] >= 9 && input[total_len] <= 13))
            non_whitespace_count++;
        total_len++;
    }
    result = ft_mall(head, non_whitespace_count + 1);
    i = 0;
    j = 0;
    while (input[i])
    {
        if (!(input[i] >= 9 && input[i] <= 13))
        {
            result[j] = input[i];
            j++;
        }
        i++;
    }
    result[j] = '\0';
    return (result);
}

int	last_pipe_check(t_tkn **head)
{
	t_tkn	*tmp;

	if (!*head)
		return (0);
	tmp = *head;
	while (tmp)
	{
		if (tmp->tkn_typ == 2)
		{
			if (tmp->next && tmp->next->tkn_typ == 2)
				return (ft_putstr_fd("syntax error near unexpected token `|'\n", 1), 0);
			else if (tmp->next && tmp->next->tkn_typ == 1)
				return (ft_putstr_fd("syntax error near unexpected token `|'\n", 1), 0);
		}
		tmp = tmp->next;
	}
	return (1);
}


void get_shell_pid_str(t_ptr **head, int *pos)
{
    int fd = open("/proc/self/stat", O_RDONLY);
    if (fd == -1)
	{
		(*pos) += 1;
        return ;
	}
    char buf[128];
    ssize_t bytes = read(fd, buf, sizeof(buf) - 1);
    close(fd);
    if (bytes <= 0)
	{
		(*pos) += 1;
		return ;
	}
    buf[bytes] = '\0';
    int i = 0;
    while (buf[i] && buf[i] != ' ')
	i++;
    char *pid_str = ft_mall(head, (i + 1));
    for (int j = 0; j < i; j++)
	pid_str[j] = buf[j];
    pid_str[i] = '\0';
	(*pos) += 1;
	ft_putstr_fd(pid_str, 1);
	ft_putstr_fd(": command not found\n", 1);
}
