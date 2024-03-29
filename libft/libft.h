/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:19:22 by mparisse          #+#    #+#             */
/*   Updated: 2023/03/24 22:18:41 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define MAXOU 18446744073709551615UL
# define MAXOU_INT_MIN -2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_abs(int nb);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *ds, const char *src, size_t size);
char	*ft_strcat(const char *dest, const char *src);
char	*ft_strcpy_maxou(char *dest, char *src);
char	*ft_itoa(int nb);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_sup_strjoin(char const *s1, char c, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strndup(char const *s, int stop);
char	*ft_strcpy_maxou(char *dest, char *src);
char	*ft_strdup(char const *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *src, const char *little, size_t len);
char	*ft_strtrim(const char *s, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char ));
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_front(t_list **lst, t_list *nouveau);
void	ft_lstadd_back(t_list **lst, t_list *nouveau);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **list, void (*del)(void *));
int		ft_isspace(char c);
void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_swap(int *a, int *b);

#endif
