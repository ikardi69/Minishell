#if !defined MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <pwd.h>
# include <sys/types.h>
# include <unistd.h>
# define LL_MAX 9223372036854775807LL

int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif // MINISHELL_H
