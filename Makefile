
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell

SRC = main.c execution/check_exec.c utils/nodes_managemet.c builts/build_pwd.c \
	builts/check_builts.c execution/creat_env.c  \
	utils/nodes_2.c utils/env_utils.c func/funct1.c func/funct2.c func/funct3.c builts/build_echo.c \
	builts/build_cd.c builts/export_utils.c builts/build_env.c builts/build_export.c builts/build_enset.c func/funct4.c \
	builts/build_exit.c execution/redirections.c execution/redirections_utils.c execution/pipes.c \
	signal/signal_handler.c utils/heredoc.c  \
    parsing/ft_pcollector.c  parsing/pars.c  parsing/pars2.c  parsing/pars3.c  parsing/red_prs.c  parsing/pars4.c \
	parsing/strc_cr.c func/funct5.c execution/pipes_utils.c parsing/pars5.c \
	parsing/pars6.c parsing/pars7.c parsing/pars8.c parsing/pars9.c parsing/pars10.c parsing/pars11.c \
	parsing/pars12.c

OBJ = ${SRC:.c=.o}
HEADER = include/exec.h

all: print_message ${NAME}


${NAME}: ${OBJ}
	@echo -e "\033[0;32mLinking objects to create ${NAME}...\033[0m"
	${CC} ${CFLAGS} ${OBJ} -lreadline -o ${NAME}
	@echo -e "\033[1;32mSuccessfully compiled ${NAME}!\033[0m"

%.o: %.c ${HEADER}
	@echo -e "\033[0;33mCompiling $<...\033[0m"
	${CC} ${CFLAGS} -I include -c $< -o $@

clean:
	@echo -e "\033[0;31mCleaning object files...\033[0m"
	rm -f ${OBJ}
	@echo -e "\033[1;32mObject files cleaned.\033[0m"

fclean: clean
	@echo -e "\033[0;31mCleaning ${NAME} executable...\033[0m"
	rm -f ${NAME}
	@echo -e "\033[1;32m${NAME} executable cleaned.\033[0m"

re: fclean all

.PHONY: clean fclean re print_message