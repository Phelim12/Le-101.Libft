/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reset.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:58:38 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:58:38 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_all_type(t_type *all_type)
{
	all_type->c = 0;
	all_type->d = 0;
	all_type->wc = 0;
	all_type->ud = 0;
	all_type->str = NULL;
	all_type->wstr = NULL;
}

t_params	reset_params(int *ptr1, int *ptr2, int first)
{
	t_params ret;

	if (first == TRUE)
	{
		*ptr1 = 0;
		*ptr2 = 0;
	}
	ret.size_precision = -1;
	ret.print_prefix = 1;
	ret.flag_hashtag = 0;
	ret.print_sign = 1;
	ret.size_width = 0;
	ret.flag_point = 0;
	ret.flag_space = 0;
	ret.flag_zero = 0;
	ret.flag_less = 0;
	ret.flag_more = 0;
	ret.size_type = 0;
	return (ret);
}
