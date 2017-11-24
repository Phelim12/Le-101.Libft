/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:08:51 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:08:51 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**	  This function returns the absolute
**	value of the integer passed as parameter.
*/

# define ABS(v)		(v < 0 ? -v : v)
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}				t_list;

/*
**	The functions returns a char ** .
*/

char			**ft_strsplit(char const *s, char c);

/*
**	The functions returns a char * .
*/

char			*ft_itoa(int n);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *s);
char			*ft_strtrim(char const *s);
char			*ft_fillstr(char *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcat(char *d, const char *s);
char			*ft_strcpy(char *d, const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strncpy(char *d, const char *s, size_t n);
char			*ft_strstr(const char *s, const char *to_find);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *s, const char *to_find, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

/*
**	The functions returns an int .
*/

int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_count_words(const char *s, int nb_words, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_count_len(const char *s, char c);
int				ft_strlen(const char *s);
int				ft_atoi(const char *s);
int				ft_next_sqrt(int nb);
int				ft_size_int(int n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_lenint(int n);
int				ft_sqrt(int nb);

/*
**	The functions returns a size_t .
*/

size_t			ft_strlcat(char *d, const char *s, size_t n);

/*
**	The functions returns a t_list .
*/

t_list			*ft_lstnew(void const *content, size_t content_size);

/*
**	The functions returns a void * .
*/

void			*ft_memalloc(size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *d, const void *s, size_t n);
void			*ft_memmove(void *d, const void *s, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t n);

/*
**	The functions returns a void .
*/

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_striter(char *s, void (*f)(char *));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_putchar(char c);
void			ft_putnbr(int n);

#endif
