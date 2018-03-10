/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_params.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 21:27:49 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 21:27:49 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_precision(t_type *all_type, t_params *flags)
{
	int ret;

	ret = 0;
	if (!(ft_strchr("diouxX", flags->type)))
		return (0);
	flags->size_precision -= flags->len_arg;
	if (flags->flag_hashtag == 2 && all_type->ud != 0)
		flags->size_precision += 2;
	if (flags->flag_more == TRUE || all_type->d < 0)
		flags->size_precision++;
	while (flags->size_precision-- > 0)
		ret += ft_putchar('0');
	flags->len_arg += ret;
	return (ret);
}

int		ft_print_sign(t_type all_type, t_params *flags)
{
	char sign;

	if (flags->print_sign == FALSE)
		return (0);
	if (flags->type == 'd' || flags->type == 'i')
	{
		if (all_type.d >= 0)
			sign = '+';
		if (all_type.d < 0)
			sign = '-';
		flags->print_sign = FALSE;
		return (ft_putchar(sign));
	}
	return (0);
}

int		ft_print_prefix(t_type a, t_params *flags)
{
	if (flags->print_prefix == 0 || !(ft_strchr("poxX", flags->type)))
		return (0);
	if (flags->flag_hashtag > 0)
	{
		if (flags->print_prefix == 1 && flags->flag_zero == FALSE)
		{
			flags->print_prefix++;
			return (0);
		}
		flags->print_prefix = 0;
		if (flags->type == 'X' && a.ud > 0)
			return (ft_putstr("0X"));
		if ((flags->type == 'x' && a.ud > 0) || flags->flag_hashtag == 2)
			return (ft_putstr("0x"));
		if (flags->type == 'o' && (a.ud > 0 || flags->flag_hashtag == TRUE))
			return (ft_putchar('0'));
	}
	flags->print_prefix = 0;
	return (0);
}

int		ft_print_width(t_type all_type, t_params *flags)
{
	int ret;

	ret = 0;
	if (flags->flag_less == FALSE)
		flags->size_width -= ft_modify_width(all_type, *flags);
	while (flags->flag_less == FALSE && flags->size_width-- > 0)
	{
		if (flags->flag_zero == TRUE)
			ret += ft_putchar('0');
		else
			ret += ft_putchar(' ');
	}
	if (flags->flag_less == TRUE)
	{
		flags->flag_zero = FALSE;
		flags->flag_less = FALSE;
	}
	return (ret);
}

int		ft_print_params(va_list ap, t_params flags)
{
	t_type	all_type;
	int		ret;

	ret = 0;
	reset_all_type(&all_type);
	ft_search_arg(ap, &all_type, &flags);
	if (flags.flag_space == TRUE && flags.flag_point <= 1)
		flags.size_width++;
	if (all_type.d == 0 && flags.type == 'd' && flags.flag_zero &&
		!(flags.flag_more))
		flags.size_width--;
	if (ft_strchr("sS", flags.type))
		ft_modify_string(&all_type, &flags);
	ret += ft_check_sign(all_type, &flags, 1);
	ret += ft_print_prefix(all_type, &flags);
	ret += ft_print_width(all_type, &flags);
	ret += ft_print_prefix(all_type, &flags);
	ret += ft_check_sign(all_type, &flags, 0);
	ret += ft_print_precision(&all_type, &flags);
	ret += ft_print_arg(all_type, flags);
	ret += ft_print_width(all_type, &flags);
	return (ret);
}
