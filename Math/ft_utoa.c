/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 15:39:21 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:39:21 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char			*ret;
	int				len;

	len = ft_ulen(n);
	ret = ft_strnew(len);
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		ret[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
