# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 19:42:46 by ababdelo          #+#    #+#              #
#    Updated: 2023/09/04 16:30:14 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===========================colors============================#

RESET_COLOR		= \033[0m
BLACK   		= \033[30m
RED     		= \033[31m
LIGHT_RED		= \033[91m
GREEN   		= \033[32m
LIGHT_GREEN		= \033[92m
YELLOW  		= \033[33m
LIGHT_YELLOW	= \033[93m
BLUE    		= \033[34m
LIGHT_BLUE		= \033[94m
MAGENTA 		= \033[35m
LIGHT_MAGENTA	= \033[95m
CYAN    		= \033[36m
LIGHT_CYAN		= \033[96m
WHITE   		= \033[37m
GREY    		= \033[90m
LIGHT_GREY		= \033[37m
MAROON			= \033[38;5;88m
BLACK			= \033[30m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
BLUE			= \033[34m
MAGENTA			= \033[35m
CYAN			= \033[36m
WHITE			= \033[37m
RESET			= \033[0m

#=============================================================#

# ========================variables============================ #

NAME = minishell
MKDIR = mkdir

CC = gcc

RM = rm -rf

LIBFTP = libraries/libft
PATHB = build/
PATHO = build/objs/
PATHS = src/
PATHSM = src/main/
PATHSL = src/lexer/
PATHSP = src/parser/
PATHSB = src/builtins/
PATHSEX = src/expand/
PATHSU = src/utils/
PATHSE = src/error/
PATHP = src/pipex/
PATHEX = src/executor/

BUILD_PATHS = $(PATHB) $(PATHO)

src	=	src/main/minishell.c \
		src/utils/signals.c \
		src/utils/utils.c \
		src/utils/t_simple_cmds_utils.c \
		src/utils/minishell_loop.c \
		src/builtins/builtins_utils.c \
		src/builtins/builtins.c \
		src/builtins/ft_env.c \
		src/builtins/ft_cd.c \
		src/builtins/ft_echo.c \
		src/builtins/ft_pwd.c \
		src/builtins/ft_export.c \
		src/builtins/ft_unset.c \
		src/builtins/ft_exit.c \
		src/error/error_handling.c \
		src/error/ft_error.c \
		src/executor/check_redirections.c \
		src/executor/handle_cmd.c \
		src/executor/heredoc.c \
		src/executor/executor.c \
		src/expand/expand_utils.c \
		src/expand/expand_utils2.c \
		src/expand/expand.c \
		src/lexer/handler.c \
		src/lexer/t_lexer_clear_utils.c \
		src/lexer/t_lexer_utils.c \
		src/lexer/token_reader.c \
		src/parser/handle_redirections.c \
		src/parser/parse_envp.c \
		src/parser/parser_utils.c \
		src/parser/parser.c

OBJS	=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(src))))

FLAGS	=	-Wall -Werror -Wextra -g #-fsanitize=address

LIBFT	=	./libraries/libft/libft.a
 
HEADER	=	.includes/list.h \
			.includes/builtins.h \
			.includes/prompt.h \
			.includes/error.h \
			.includes/executor.h \
			.includes/expand.h \
			.includes/lexer.h \
			.includes/parser.h \
			.includes/utils.h \
			.includes/minishell.h

READLINE_DIR = /usr/local/opt/readline

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib
	
INCLUDES =-Iincludes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include 
 
# ============================================================= #

# ==========================rules============================== #

all: $(BUILD_PATHS) $(NAME)

$(PATHO)%.o:: $(PATHSM)%.c
	@echo "Compiling ${notdir $<}			in	$(PATHS)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSM)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSM)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSL)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSL)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSP)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSP)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSB)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSB)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSEX)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSEX)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSU)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSU)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSE)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSE)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHEX)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHEX)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS) 
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(READLINE_LIB) -o $(NAME)
	@$(RM) $(PATHB) 
	@echo "Success"

$(LIBFT):
	@$(MAKE) -C ./libraries/libft

$(PATHB):
	@$(MKDIR) $(PATHB)

$(PATHO):
	@$(MKDIR) $(PATHO)

clean:
	@echo "Cleaning"
	@$(RM) $(OBJS)
	@$(RM) $(PATHB).tmp*
	@$(RM) $(PATHO) $(PATHB)
	@make fclean -C libraries/libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

.PRECIOUS: $(PATHO)%.o

.PHONY: all clean fclean re
# ============================================================= #