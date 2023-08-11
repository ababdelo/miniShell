# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 15:33:56 by ababdelo          #+#    #+#              #
#    Updated: 2023/08/11 15:48:47 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================== Colors ========================== #
BLACK  = \033[0;30m
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
PURPLE = \033[0;35m
CYAN   = \033[0;36m
GREY   = \033[0;90m
WHITE  = \033[0m
# ============================================================= #

# ======================== Variables ========================== #
PRGM = minishell

MAKE_MSG = --->> Mandatory part has been compiled successfully

CLN_MSG = --->> ' .o ' files has been removed successfully

FCLN_MSG = --->> executable file ' $(PRGM) ' has been removed successfully

ASAN_MSG = --->> Compiled Program with AddressSanitizer

CC = cc

RM = rm -f

TFLAGS = -lpthread

CFLAGS = -Wall -Wextra -Werror

ASAN_FLAGS = -fsanitize=address -g3

SRCS = MS.c Organizer.c Parser.c Elements_cntr.c LIBFT_UT1.c LIBFT_UT2.c

OBJS = $(SRCS:.c=.o)
# ============================================================= #

# ========================== Rules ============================ #
all : $(PRGM)

$(PRGM) : $(OBJS)
	@echo "${GREEN}$(MAKE_MSG)${WHITE}" \
	&& $(CC) $(CFLAGS) $(TFLAGS) $(OBJS) -o $(PRGM)

clean :
	@echo "${YELLOW}$(CLN_MSG)${WHITE}" \
	&& $(RM) $(OBJS)

fclean : clean
	@echo "${RED}$(FCLN_MSG)${WHITE}" \
	&& $(RM) $(PRGM)

re : fclean all

asan : CFLAGS += $(ASAN_FLAGS)
asan : $(PRGM)
	@echo "${CYAN}$(ASAN_MSG)${WHITE}"

.PHONY: all clean fclean re asan
# ============================================================= #