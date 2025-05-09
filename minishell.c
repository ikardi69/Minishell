/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:10:06 by ikardi            #+#    #+#             */
/*   Updated: 2025/05/09 17:57:47 by mteffahi         ###   ########.fr       */
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

int main(int argc, char **argv, char **env)
{
	char *input;
	char	*uid;
	struct passwd *pw;

	(void)argc;
	(void)argv;
	(void)env;
	// uid = getenv("LOGNAME");
	// if (!uid)
	// 	return (perror("UID not found in envirment\n"), 1);
	// pw = getpwuid((uid_t)ft_atoi(uid));
	// print_double_ptr(env);
	print_env(pw);
	while (1)
	{
		input = readline("Minishell --> : ");
		if (!input)
			break ;
		else
			add_history(input);
	}
	return (0);
}
