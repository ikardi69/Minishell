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

typedef enum e_tkn_type
{
	NULL_Tk,
	wrd,
	PI,		// |
	red_in,		// <
	red_out,	// >
	red_apnd,	// >>
	HEREDOC		// <<
}t_tkn_type;

typedef struct s_tkn
{
	char			*vl;
	t_tkn_type		tkn_typ;
	struct s_tkn	*next;
}t_tkn;


int	    	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(t_ptr **head, char const *s1, char const *s2);
char		*ft_strdup(t_ptr **head, const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		add_node(t_ptr **head, void *ptr);
void    	*ft_mall(t_ptr **head, ssize_t size);
void		ft_lstadd_back(t_ptr **lst, t_ptr *new);
void		ft_lstclear(t_ptr **lst, void (*del)(void*));
/*parsing starting*/
void		pars(t_ptr **head, char *input);
int			check_q(char *input, int i);
int			checker_synx(char *input, char check);
void		first_q(char *input);
void		ft_putstr_fd(char *s, int fd);
void    	invalid_sqnc(char *input);
int 		ft_strcmp(char *s1, char *s2);
/**********************************************************************************************/
int			is_qtd(char *input);
void		ft_lstadd_back_tkn(t_tkn **lst, t_tkn *new);
t_tkn_type	identify_tkn(char *val);
int			splt_quoted(t_ptr **head, t_tkn **token, char *input, int *i);
int			splt(t_ptr **head, t_tkn **token, char *input, int *i);
void		creat_tkn_node(t_ptr **head, t_tkn **tkn_head, char *val, t_tkn_type type);

#endif
