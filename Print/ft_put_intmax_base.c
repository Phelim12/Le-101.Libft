/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_intmax_base.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 19:05:06 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 19:05:06 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_intmax_base(intmax_t nbr, char *base, int sign)
{
	char	*str;
	int		ret;

	str = ft_imaxtoa_base(nbr, base);
	if (sign == 0 && str[0] == '-')
		str++;
	ret = ft_putstr(str);
	free(str);
	return (ret);
}
