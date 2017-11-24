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
	char		*ret;
	int			len;
	long int	s_n;

	s_n = n;
	len = ft_lenint(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len--] = '\0';
	if (!n)
		ret[len--] = '0';
	s_n = ABS(s_n);
	while (s_n)
	{
		ret[len--] = (s_n % 10) + '0';
		s_n /= 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
