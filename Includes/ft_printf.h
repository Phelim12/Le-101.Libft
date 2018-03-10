/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 16:46:29 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 16:46:29 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <wchar.h>
# include <stdarg.h>
# include "libft.h"

# define PRINTF_TYPE "sSpdDioOuUxXcCeEfFgGaAn%"
# define PRINTF_SPECS "#0-+ *123456789.hljz$L’'"

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃         This structure groups all the parameters of the argument           ┃
**┃                           passed to ft_printf                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_params
{
	char	flag_hashtag;
	char	flag_space;
	char	flag_zero;
	char	flag_less;
	char	flag_more;
	char	flag_point;
	char	size_type;
	int		print_sign;
	int		print_prefix;
	int		size_width;
	int		size_precision;
	int		len_arg;
	char	type;
}				t_params;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃      This structure groups all the types of variables that will be         ┃
**┃                        used when using ft_printf                           ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_type
{
	char		c;
	char		*str;
	wchar_t		wc;
	wchar_t		*wstr;
	intmax_t	d;
	uintmax_t	ud;
}				t_type;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               modify_flags.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_modify_params(t_params *flags);
void			ft_modify_string(t_type *all_type, t_params *flags);
int				ft_check_sign(t_type all_type, t_params *flags, int first);
int				ft_modify_width(t_type all_type, t_params flags);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               ft_printf.c                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_printf(const char *format, ...);
int				ft_vdprintf(const char *format, va_list ap);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              find_params.c                                 ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_find_flags(char specs, t_params *ptr);
int				ft_find_width(char *specs, t_params *ptr);
int				ft_find_precision(char *specs, t_params *ptr);
int				ft_find_size(char *specs, t_params *ptr);
int				ft_find_params(va_list ap, char *specs, t_params *ptr);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              search_arg.c                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_arg_str(va_list ap, t_type *all_type, t_params *flags);
void			ft_arg_char(va_list ap, t_type *all_type, t_params *flags);
void			ft_arg_int(va_list ap, t_type *all_type, t_params *flags);
void			ft_search_arg(va_list ap, t_type *all_type, t_params *flags);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 reset.c                                    ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			reset_all_type(t_type *all_type);
t_params		reset_params(int *ptr1, int *ptr2, int first);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                               print_arg.c                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_print_txt(t_type all_type, t_params flags);
int				ft_print_arg(t_type all_type, t_params flags);
int				ft_print_int(t_type all_type, t_params flags, int ret);
int				ft_print_conv(char *base, uintmax_t ud, t_params flags);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                len_arg.c                                   ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_len_arg(t_type all_type, t_params flags);
int				ft_len_conv(t_type all_type, t_params flags);
int				ft_size_prefix(t_type all_type, t_params flags);
int				ft_len_precision(t_type all_type, t_params flags);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              print_params.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				ft_print_precision(t_type *all_type, t_params *flags);
int				ft_print_sign(t_type all_type, t_params *flags);
int				ft_print_prefix(t_type a, t_params *flags);
int				ft_print_width(t_type all_type, t_params *flags);
int				ft_print_params(va_list ap, t_params flags);

#endif
