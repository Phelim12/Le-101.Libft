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

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		a;

	va_start(ap, format);
	a = ft_vdprintf(format, ap);
	va_end(ap);
	return (a);
}

int		ft_vdprintf(const char *format, va_list ap)
{
	t_params	params;
	int			cur;
	int			ret;

	params = reset_params(&ret, &cur, TRUE);
	while (format[cur])
	{
		if (format[cur] == '%')
		{
			while (format[++cur] && ft_strchr(PRINTF_SPECS, format[cur]))
				cur += ft_find_params(ap, (char *)(format + cur), &params);
			if (format[cur])
			{
				params.type = format[cur];
				ret += ft_print_params(ap, params);
				params = reset_params(&ret, &cur, FALSE);
				cur++;
			}
		}
		else
			ret += ft_putchar(format[cur++]);
	}
	return (ret);
}
