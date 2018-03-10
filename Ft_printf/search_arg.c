/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 19:51:08 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 19:51:08 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_str(va_list ap, t_type *all_type, t_params *flags)
{
	if (flags->type == 'S')
		all_type->wstr = va_arg(ap, wchar_t*);
	else if (flags->type == 's')
		all_type->str = va_arg(ap, char*);
}

void	ft_arg_char(va_list ap, t_type *all_type, t_params *flags)
{
	if (flags->type == 'C')
		all_type->wc = va_arg(ap, wchar_t);
	else if (flags->type == 'c')
		all_type->c = (char)va_arg(ap, int);
	else if (ft_strchr("di", flags->type))
		all_type->d = (char)va_arg(ap, int);
	else if (ft_strchr("ouxX", flags->type))
		all_type->ud = (unsigned char)va_arg(ap, unsigned int);
}

void	ft_arg_int(va_list ap, t_type *all_type, t_params *flags)
{
	if (ft_strchr("jlL", flags->size_type) && ft_strchr("di", flags->type))
		all_type->d = va_arg(ap, intmax_t);
	else if (ft_strchr("jlL", flags->size_type) &&
	ft_strchr("ouxX", flags->type))
		all_type->ud = va_arg(ap, uintmax_t);
	else if (flags->size_type == 'h' && ft_strchr("di", flags->type))
		all_type->d = (short)va_arg(ap, int);
	else if (flags->size_type == 'h' && ft_strchr("ouxX", flags->type))
		all_type->ud = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->size_type == 'z' && ft_strchr("di", flags->type))
		all_type->d = (ssize_t)va_arg(ap, ssize_t);
	else if (flags->size_type == 'z' && ft_strchr("ouxX", flags->type))
		all_type->ud = (size_t)va_arg(ap, size_t);
	else if (ft_strchr("di", flags->type))
		all_type->d = (int)va_arg(ap, int);
	else if (ft_strchr("ouxX", flags->type))
		all_type->ud = (unsigned int)va_arg(ap, unsigned int);
}

void	ft_search_arg(va_list ap, t_type *all_type, t_params *flags)
{
	ft_modify_params(flags);
	if (flags->size_type == 'H' && ft_strchr("diouxXcC", flags->type))
		ft_arg_char(ap, all_type, flags);
	else if (ft_strchr("cC", flags->type))
		ft_arg_char(ap, all_type, flags);
	else if (ft_strchr("sS", flags->type))
		ft_arg_str(ap, all_type, flags);
	else if (ft_strchr("diouxX", flags->type))
		ft_arg_int(ap, all_type, flags);
	else if (!(ft_strchr(PRINTF_TYPE, flags->type)) && flags->type)
	{
		all_type->wc = (wchar_t)flags->type;
		flags->type = 'C';
	}
	flags->len_arg = ft_len_arg(*all_type, *flags);
}
