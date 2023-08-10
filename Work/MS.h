/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MS.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:22:16 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/10 18:55:04 by elel-yak         ###   ########.fr       */
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
	char *limiter;
	struct s_hdoc *next;
}	t_hdoc;
typedef struct s_args
{
	char *arg;
	struct s_args *next;
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

int		wrd_cnt(char const *s, char del);

size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	**ft_split(char const *s, char c);
char	**ft_free(char **str, int x);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *str, const char *to_f, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);


/*************************************************************************/
int pipe_cntr(char *str);
int lredir_cntr(char *str);
int rredir_cntr(char *str);
int herd_cntr(char *str);

char *str_norm(char *str);
char *organizer(int index, int nindex, int cntr, char *str);
void	add_spc(int *index, int *nindex, char *str,char **out);
/************************************************************************/
#endif
