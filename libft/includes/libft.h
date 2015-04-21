/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:00:38 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 14:14:00 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# define BUFF_SIZE 4096

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct		s_tree
{
	void			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

void				ft_strdel(char **as);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(const char *str);
void				ft_putendl(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_freesplit(char **split);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isdigit(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_atoi(const char *s1);
int					ft_strlen(const char *s);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					get_next_line(int const fd, char **line);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_itoa(int n);
char				**ft_strsplit(const char *s, char c);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strmap(const char *s, char(*f)(char));
char				*ft_strmapi(const char *s, char(*f)(unsigned int, char));
char				*ft_strtrim(const char *s);
t_list				*ft_list_new(void const *content);
void				ft_list_push_back(t_list **begin_list, void *content);
void				ft_list_push_front(t_list **begin_list, void *content);
void				ft_list_free(t_list **begin_list, void (*fct)(void *));
void				ft_list_del_elem(t_list **begin_list, t_list *elem,
void				(*fct)(void *));
t_tree				*ft_tree_new(const void *content);
void				ft_tree_push_left(t_tree **root, const void *content);
void				ft_tree_push_right(t_tree **root, const void *content);
void				ft_tree_push_back_right(t_tree **root, const void *content);
float				ft_atoif(const char *str);

#endif
