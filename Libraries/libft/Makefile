# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+      #
#    By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 15:33:56 by ababdelo          #+#    #+#              #
#    Updated: 2023/09/03 10:46:02 by ababdelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ======================== Variables ========================== #
PRGM = libft.a

CC = cc

RM = rm -rf

AR = ar -ru

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_arrdup.c\
			ft_lstadd_back.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
			ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memset.c ft_memmove.c ft_re_split_str.c ft_join_split_str.c\
			ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putnbr_base.c ft_putchar_fd.c ft_putendl_fd.c\
			ft_split.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
			ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_is_wide_space.c ft_skip_spaces.c\
			PRINTF/ft_printf.c\
			GNL/GNL.c GNL/GNL_Utils.c

OBJS = $(SRCS:.c=.o)

HEADERFILES := libft.h

# ============================================================= #

# ========================== Rules ============================ #
all: $(PRGM)

%.o: %.c $(HEADERFILES)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(PRGM): $(OBJS)
	@$(AR) $(PRGM) $^
	@echo "Libft succesfully created"

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(PRGM)

re : fclean all

.PHONY: all clean fclean re
# ============================================================= #