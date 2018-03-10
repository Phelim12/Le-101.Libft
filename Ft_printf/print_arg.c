/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 16:17:55 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 16:17:55 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_txt(t_type all_type, t_params flags)
{
	if (flags.type == 'c')
	{
		if (ft_isascii(all_type.c))
			return (ft_putchar(all_type.c));
		return (write(1, &all_type.c, 1));
	}
	if (flags.type == 'C')
		return (ft_putwchar(all_type.wc));
	if (flags.type == 's')
	{
		if (!(all_type.str) && flags.flag_point == FALSE)
			return (ft_putstr("(null)"));
		return (ft_putstr(all_type.str));
	}
	if (flags.type == 'S')
	{
		if (!(all_type.wstr) && flags.flag_point == FALSE)
			return (ft_putstr("(null)"));
		return (ft_putwstr(all_type.wstr));
	}
	return (0);
}

int		ft_print_conv(char *base, uintmax_t ud, t_params flags)
{
	int ret;

	ret = 0;
	if (flags.flag_hashtag == 2 && ud == 0 && flags.flag_point)
		return (0);
	if (flags.flag_hashtag == TRUE && flags.type == 'o' && ud == 0)
		return (0);
	if (flags.flag_point > 0 && ud == 0 && flags.size_width == -1)
		return (ft_putchar(' '));
	if (flags.flag_point > 0 && ud == 0)
		return (0);
	if (ft_strchr("jlzL", flags.size_type))
		ret = ft_put_uintmax_base(ud, base);
	else
		ret = ft_put_uint_base(ud, base);
	return (ret);
}

int		ft_print_int(t_type all_type, t_params flags, int ret)
{
	if (flags.type == 'd' || flags.type == 'i')
	{
		if (flags.flag_point == TRUE && all_type.d == 0)
			return (0);
		if (flags.size_type == 'h')
			ft_putnbr(FT_ABS(all_type.d));
		else
			ft_put_uintmax(FT_ABS(all_type.d));
		ret = ft_imaxlen(all_type.d);
	}
	else if (flags.type == 'u')
	{
		if (flags.flag_point > 0 && all_type.ud == 0)
			return (0);
		ret = ft_put_uintmax_base(all_type.ud, "0123456789");
	}
	else if (flags.type == 'o')
		ret = ft_print_conv("01234567", all_type.ud, flags);
	else if (flags.type == 'x')
		ret = ft_print_conv("0123456789abcdef", all_type.ud, flags);
	else if (flags.type == 'X')
		ret = ft_print_conv("0123456789ABCDEF", all_type.ud, flags);
	return (ret);
}

int		ft_print_arg(t_type all_type, t_params flags)
{
	int ret;

	ret = 0;
	if (flags.type == '%')
		return (ft_putchar('%'));
	if (ft_strchr("cCsS", flags.type))
		ret = ft_print_txt(all_type, flags);
	if (ft_strchr("diouxX", flags.type))
		ret = ft_print_int(all_type, flags, 0);
	return (ret);
}
