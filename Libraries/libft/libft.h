/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:05:58 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/01 13:29:53 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define DEC_BASE "0123456789"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_lstsize(t_list *lst);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

void	*ft_memset(void *str, int c, size_t n);
void	*ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	free_arr(char **split_arr);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *str, int *len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base(unsigned long nbr, char *base, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_putchar(char c, int *len);

char	*ft_strchr(char *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**ft_arrdup(char **arr);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//GET_NEXT_LINE
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_create_line(char *saved);
char	*ft_remove_line(char *saved);
int		ft_check_nl(char *input);
char	*commit_join(char *s1, char *s2);
char	*read_buff(int fd, char *saved);
char	*get_next_line(int fd);

//PRINTF
int		ft_printf(const char *form, ...);
int		ft_print(const char *form, va_list args, int *len);
void	ft_check(const char *form, va_list args, int *x);

#endif
