/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:07:02 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/04 11:46:02 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libraries/libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "list.h"
# include <dirent.h>
# include <signal.h>
# include "prompt.h"
# include "parser.h"
# include "utils.h"
# include "error.h"
# include "lexer.h"
# include "builtins.h"
# include "expand.h"
# include "executor.h"

#endif
