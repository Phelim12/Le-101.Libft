/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 15:16:18 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:16:18 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 32
# define FT_ABS(x)	(x < 0 ? -x : x)
# define FT_NEG(x)	(x < 0 ? 1 : 0)
# define FALSE 0
# define TRUE 1

# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "ft_printf.h"

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                        structure of my linked list                        ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}				t_list;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             Char : Functions                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_size_wchar(wchar_t w);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             Math : Functions                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_ilen(int n);
char			*ft_itoa(int n);
int				ft_sqrt(int nb);
int				ft_next_sqrt(int nb);
int				ft_ceil(float result);
int				ft_atoi(const char *s);
unsigned int	ft_atou(const char *s);
int				ft_imaxlen(intmax_t n);
char			*ft_imaxtoa(intmax_t n);
int				ft_ulen(unsigned int n);
int				ft_umaxlen(uintmax_t n);
char			*ft_umaxtoa(uintmax_t n);
char			*ft_utoa(unsigned int n);
intmax_t		ft_atoimax(const char *s);
uintmax_t		ft_atoumax(const char *s);
int				ft_hexatoi(const char *s);
void			ft_sort_tab_ascii(char ***av);
int				ft_ilen_base(int n, int base);
char			*ft_itoa_base(int nbr, char *base);
int				ft_imaxlen_base(intmax_t n, int base);
int				ft_ulen_base(unsigned int n, int base);
int				ft_umaxlen_base(uintmax_t n, int base);
char			*ft_imaxtoa_base(intmax_t nbr, char *base);
char			*ft_umaxtoa_base(uintmax_t nbr, char *base);
char			*ft_utoa_base(unsigned int nbr, char *base);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            Print : Functions                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_putnbr(int n);
int				ft_putchar(char c);
int				ft_putwchar(wchar_t w);
int				ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_put_intmax(intmax_t n);
int				ft_putwstr(wchar_t *wstr);
void			ft_put_uint(unsigned int n);
void			ft_put_uintmax(uintmax_t n);
void			ft_putnbr_fd(int n, int fd);
int				ft_utf8_1(wchar_t w, int fd);
int				ft_utf8_2(wchar_t w, int fd);
int				ft_utf8_3(wchar_t w, int fd);
int				ft_utf8_4(wchar_t w, int fd);
int				ft_putchar_fd(char c, int fd);
int				ft_putwchar_fd(wchar_t w, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
int				ft_putnbr_base(int nbr, char *base, int sign);
int				ft_put_uint_base(unsigned int nbr, char *base);
int				ft_put_intmax_base(intmax_t nbr, char *base, int sign);
int				ft_put_uintmax_base(uintmax_t nbr, char *base);
/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            Memory : Functions                             ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_memdel(void **ap);
void			ft_tabdel(char **tab);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *d, const void *s, size_t n);
void			*ft_memmove(void *d, const void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t n);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                          Linked list : Functions                          ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_lstadd(t_list **alst, t_list *new);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             String : Functions                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_strclr(char *s);
void			ft_strdel(char **as);
char			*ft_strrev(char *str);
char			*ft_strnew(size_t size);
int				ft_strlen(const char *s);
int				ft_wstrlen(wchar_t *wstr);
char			*ft_strdup(const char *s);
char			*ft_strtrim(const char *s);
int				ft_str_is_number(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcpy(char *d, const char *s);
char			*ft_strcat(char *d, const char *s);
char			**ft_strsplit(const char *s, char c);
void			ft_striter(char *s, void (*f)(char *));
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(const char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *d, const char *s, size_t n);
char			*ft_strncpy(char *d, const char *s, size_t n);
char			*ft_strstr(const char *s, const char *to_find);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
wchar_t			*ft_wstrncpy(wchar_t *d, const wchar_t *s, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *s, const char *to_find, size_t n);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
wchar_t			*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len);

int				get_next_line(int const fd, char **line);

#endif
