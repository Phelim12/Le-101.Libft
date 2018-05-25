/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_umaxtoa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 15:39:47 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:39:47 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_umaxtoa(uintmax_t n)
{
	char		*ret;
	int			len;

	len = ft_umaxlen(n);
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
