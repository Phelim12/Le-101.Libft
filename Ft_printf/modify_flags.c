/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modify_flags.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 17:46:02 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/23 17:46:02 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_string(t_type *all_type, t_params *flags)
{
	int pre;

	pre = flags->size_precision;
	if (flags->type == 's' && flags->flag_point > 0 && all_type->str)
	{
		if (pre > 0)
			all_type->str = ft_strsub(all_type->str, 0, pre);
		else
			all_type->str = ft_strsub(all_type->str, 0, 0);
		flags->len_arg = ft_strlen(all_type->str);
	}
	if (flags->type == 'S' && flags->flag_point > 0 && all_type->wstr)
	{
		if (pre > 0)
			all_type->wstr = ft_wstrsub(all_type->wstr, 0, pre);
		else
			all_type->wstr = ft_wstrsub(all_type->wstr, 0, 0);
		flags->len_arg = ft_wstrlen(all_type->wstr);
	}
	if (flags->type == 's' && all_type->str && ft_strlen(all_type->str) == 0 &&
		flags->flag_space == TRUE)
		flags->size_width--;
	if (flags->type == 'S' && all_type->wstr && !(ft_wstrlen(all_type->wstr)) &&
		flags->flag_space == TRUE)
		flags->size_width--;
}

int		ft_check_sign(t_type all_type, t_params *flags, int first)
{
	if (!(ft_strchr("diu", flags->type)))
		return (0);
	if (first && !(flags->flag_zero) &&
		(flags->size_width - flags->len_arg) > 0)
		return (0);
	if (first && flags->flag_zero && (flags->flag_more || all_type.d < 0))
		return (ft_print_sign(all_type, flags));
	if (flags->flag_more == TRUE || all_type.d < 0)
		return (ft_print_sign(all_type, flags));
	if (first && flags->flag_space && ft_strchr("di", flags->type) &&
		flags->size_precision < 0)
		return (ft_putchar(' '));
	return (0);
}

int		ft_modify_width(t_type all_type, t_params flags)
{
	int precision;
	int width;

	width = flags.size_width;
	precision = flags.size_precision;
	if (flags.flag_space == TRUE && flags.flag_point == TRUE &&
		width > 0 && width <= precision)
		return (width - 1);
	if (ft_strchr("sS", flags.type) && (!(all_type.str) && !(all_type.wstr)) &&
	flags.flag_zero == TRUE)
		return (0);
	if ((width + flags.len_arg) <= precision && !(ft_strchr("sS", flags.type)))
		return (width);
	else if (ft_strchr("di", flags.type) && flags.len_arg < precision)
	{
		if (flags.flag_space == TRUE)
			precision++;
		return ((all_type.d < 0) ? (precision + 1) : (precision));
	}
	else
		return (flags.len_arg + (ft_len_precision(all_type, flags)));
}

void	ft_modify_params(t_params *flags)
{
	if (ft_strchr("DOU", flags->type))
	{
		flags->type += 32;
		flags->size_type = 'L';
	}
	if (flags->type == 'p')
	{
		flags->type = 'x';
		flags->size_type = 'L';
		flags->flag_hashtag = 2;
	}
	if (flags->type == 'c' && flags->size_type == 'l')
		flags->type = 'C';
	if (flags->type == 's' && flags->size_type == 'l')
		flags->type = 'S';
}
