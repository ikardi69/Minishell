/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:10:06 by ikardi            #+#    #+#             */
/*   Updated: 2025/05/14 16:10:07 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_double_ptr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

void	print_env(struct passwd *env)
{
	printf("%s\n", env->pw_name);
	printf("%s\n", env->pw_passwd);
	printf("%d\n", (int)env->pw_uid);
	printf("%d\n", (int)env->pw_gid);
	printf("%s\n", env->pw_gecos);
	printf("%s\n", env->pw_dir);
	printf("%s\n", env->pw_shell);
}

void	print_ptr(t_ptr **head)
{
	t_ptr	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp && tmp->next)
	{
		printf("%p\n", tmp->ptr);
		tmp = tmp->next;
	}
}

int main(int argc, char **argv, char **env)
{
	char *input;
	t_ptr	*head;
	// char	*uid;
	// struct passwd *pw;

	(void)argc;
	(void)argv;
	head = NULL;
	add_node(&head, NULL);
	if (!head)
		return (ft_mall(NULL, -1), 0);
	// (void)env;
	// uid = getenv("LOGNAME");
	// if (!uid)
	// 	return (perror("UID not found in envirment\n"), 1);
	// pw = getpwuid((uid_t)ft_atoi(uid));
	print_double_ptr(env);
	while (1)
	{
		input = readline("Minishell --> : ");
		if (!input)
			ft_mall(&head, -1);
		else
		{
			add_history(input);
			add_node(&head, input);
			print_ptr(&head);
			pars(input);
		}
	}
	return (0);
}
