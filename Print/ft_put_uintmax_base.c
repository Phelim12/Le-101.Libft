/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_uintmax_base.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 19:05:04 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 19:05:04 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_uintmax_base(uintmax_t nbr, char *base)
{
	char	*str;
	int		ret;

	str = ft_umaxtoa_base(nbr, base);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}
