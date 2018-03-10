/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_uint_base.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 19:05:11 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 19:05:11 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_uint_base(unsigned int nbr, char *base)
{
	char	*str;
	int		ret;

	if (nbr > 4294967295)
		return (ft_putchar('0'));
	str = ft_utoa_base(nbr, base);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}
