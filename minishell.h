#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <pwd.h>
# include <sys/types.h>
# include <unistd.h>
# define LL_MAX 9223372036854775807LL

typedef struct s_ptr
{
	void        *ptr;
	struct s_ptr *next;
}t_ptr;

int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	add_node(t_ptr **head, void *ptr);
void    *ft_mall(t_ptr **head, ssize_t size);
void	ft_lstadd_back(t_ptr **lst, t_ptr *new);
void	ft_lstclear(t_ptr **lst, void (*del)(void*));
/*parsing starting*/
void	pars(char *input);
int		check_q(char *input, int i);
int		checker_synx(char *input, char check);
void	first_q(char *input);

#endif // MINISHELL_H
