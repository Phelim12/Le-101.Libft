/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_imaxtoa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 15:40:18 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:40:18 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(intmax_t n)
{
	intmax_t	s_n;
	char		*ret;
	int			len;

	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	s_n = n;
	len = ft_imaxlen(n);
	ret = ft_strnew(len);
	if (!ret)
		return (0);
	if (n > 0)
		len--;
	else if (n == 0)
		ret[0] = '0';
	else
		ret[0] = '-';
	s_n = FT_ABS(s_n);
	while (s_n)
	{
		ret[len--] = (s_n % 10) + '0';
		s_n /= 10;
	}
	return (ret);
}
