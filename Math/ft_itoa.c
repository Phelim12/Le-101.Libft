/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:03:05 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:03:05 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	s_n;
	char		*ret;
	int			len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s_n = n;
	len = ft_ilen(n);
	ret = ft_strnew(len + 1);
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
