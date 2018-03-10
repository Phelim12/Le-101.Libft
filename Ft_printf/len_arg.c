/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   len_arg.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 16:24:13 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 16:24:13 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_str(t_type all_type, t_params flags)
{
	if (flags.type == 's' && all_type.str)
		return (ft_strlen(all_type.str));
	if (flags.type == 's' && !(all_type.str))
		return (6);
	if (flags.type == 'S' && all_type.wstr)
		return (ft_wstrlen(all_type.wstr));
	if (flags.type == 'S' && !(all_type.wstr))
		return (6);
	return (0);
}

int		ft_len_precision(t_type all_type, t_params flags)
{
	int ret;

	ret = 0;
	if (!(ft_strchr("diouxX", flags.type)))
		return (0);
	flags.size_precision -= flags.len_arg;
	if (flags.flag_more == TRUE || all_type.d < 0)
		flags.size_precision++;
	while (flags.size_precision-- > 0)
		ret++;
	return (ret);
}

int		ft_size_prefix(t_type all_type, t_params flags)
{
	if (flags.type == '%')
		return (1);
	if ((flags.type == 'X' || flags.type == 'x') && flags.flag_hashtag > 0 &&
		(flags.size_precision < 1 || flags.flag_hashtag == 2))
		return (2);
	if ((((flags.type == 'O' || flags.type == 'o') && flags.flag_hashtag)))
		return (1);
	if ((flags.flag_more == TRUE || all_type.d < 0))
		return (1);
	if (flags.flag_space == TRUE && flags.flag_more == FALSE &&
		(flags.size_precision < ft_imaxlen(all_type.d)) &&
		(flags.flag_point == TRUE || flags.flag_point == FALSE))
		return (1);
	return (0);
}

int		ft_len_conv(t_type all_type, t_params flags)
{
	if (flags.size_type == 'H' && (flags.type == 'x' || flags.type == 'X'))
		return (ft_imaxlen_base(all_type.c, 16));
	if (flags.size_type == 'H' && (flags.type == 'o' || flags.type == 'O'))
		return (ft_imaxlen_base(all_type.c, 8));
	if ((flags.type == 'x' || flags.type == 'X') && flags.flag_hashtag != 2)
		return (ft_umaxlen_base(all_type.ud, 16));
	if (flags.type == 'o' || flags.type == 'O')
		return (ft_umaxlen_base(all_type.ud, 8));
	if (flags.flag_hashtag == 2)
		return (ft_umaxlen_base(all_type.ud, 16));
	return (0);
}

int		ft_len_arg(t_type all_type, t_params flags)
{
	int prefix;

	if (flags.type == 'x' && flags.flag_hashtag == 2 && all_type.ud == 0
		&& flags.flag_point && flags.size_precision >= 1)
		return (0);
	prefix = ft_size_prefix(all_type, flags);
	if (ft_strchr("sS", flags.type))
		return (ft_len_str(all_type, flags));
	if (flags.type == 'c' || flags.type == 'C')
		return (1);
	if (ft_strchr("OoXx", flags.type))
		return ((ft_len_conv(all_type, flags)) + prefix);
	if (ft_strchr("Ddi", flags.type) && flags.flag_point && !(all_type.d))
		return (0);
	if (ft_strchr("Ddi", flags.type))
		return (ft_imaxlen(all_type.d) + prefix);
	if (flags.type == 'U' || flags.type == 'u')
		return (ft_umaxlen(all_type.ud));
	if (!(ft_strchr(PRINTF_TYPE, flags.type)) && flags.type)
		return (1);
	else
		return (prefix);
}
