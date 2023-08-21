/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:43:53 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/21 18:00:30 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

int		handle_quotes(int i, char *str, char del);

//t_lexer_utils
t_lexer	*ft_lexernew(char *str, int token);
void	ft_lexeradd_back(t_lexer **lst, t_lexer *new);
void	ft_lexerdelone(t_lexer **lst, int i);
void	ft_lexerclear(t_lexer **lst);

#endif