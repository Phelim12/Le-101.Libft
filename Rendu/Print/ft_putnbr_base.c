/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 19:05:12 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 19:05:12 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base(int nbr, char *base, int sign)
{
	char	*str;
	int		ret;

	str = ft_itoa_base(nbr, base);
	if (sign == 0 && str[0] == '-')
		str++;
	ret = ft_putstr(str);
	free(str);
	return (ret);
}
