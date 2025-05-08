/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikardi <ikardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:10:06 by ikardi            #+#    #+#             */
/*   Updated: 2025/05/08 14:05:47 by ikardi           ###   ########.fr       */
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

int main(int argc, char **argv, char **env)
{
	char *input;
	char	*uid;
	struct passwd *pw;

	(void)argc;
	(void)argv;
	(void)env;
	uid = getenv("LOGNAME");
	if (!uid)
		return (perror("UID not found in envirment\n"), 1);
	pw = getpwuid((uid_t)ft_atoi(uid));
	// print_double_ptr(env);
	while (1)
	{
		input = readline(pw->pw_shell);
		if (!input)
			break ;
		else
			add_history(input);
	}
	return (0);
}
