/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MS.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:22:16 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/12 16:08:58 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_H
#define MS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_hdoc
{
	char	*limiter;
	struct	s_hdoc *next;
}	t_hdoc;

typedef struct s_args
{
	char	*arg;
	struct	s_args *next;
}	t_args;

typedef struct s_cmd
{
	int		infile;
	int		outfile;
	char	*cmd;
	t_args	*args;
	t_hdoc	*herdoc;
	bool	appand;		
}	t_cmd;

typedef struct s_data
{
	t_cmd	*cmd;
	char	**argv;
	char	**envir;
	char	**paths;
	int		infile_;
	int		outfile_;
	int		cntr_;
}	t_data;

typedef struct s_splitval
{
	int		cntr;
	int		*pos;
	int		len;
	int		wrd_len;
	int		str_index;
	int		pos_index;
	int		ret_index;
	int		index;
	char	**ret;
}	t_splitval;

/******************* Organizer && Element's counter *********************/
int		pipe_cntr(char *str);
int		lredir_cntr(char *str);
int		rredir_cntr(char *str);
int		herd_cntr(char *str);
int		append_cntr(char *str);

char	*str_norm(char *str);
char	*organizer(int index, int nindex, int cntr, char *str);
void	add_spc(int *index, int *nindex, char *str,char **out);
void	add_spc2(int *index, int *nindex, char *str,char **out);
int		add_spc3(int *index, int *nindex, char *str,char **out);
int		add_spc4(int *index, int *nindex, char *str,char **out);
/************************************************************************/

/***************************** Parser ***********************************/
void	ft_parser(char *str, t_splitval *splitval);
/************************************************************************/

/************************** SPLIT_UTILS *********************************/

size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_wrdlen(char const *str, char sep);

int		*sep_pos(char const *str, char sep, int cntr);
int		word_cnt(char const *s, char del);
int		sval_initializer(t_splitval *splitval, char *str, char sep);

char	**split_prt1(char *str, char sep, t_splitval *splitval);

void	helper(int *index, char const *str);
void	split_prt2(t_splitval *splitval, char *str);
/************************************************************************/
#endif
