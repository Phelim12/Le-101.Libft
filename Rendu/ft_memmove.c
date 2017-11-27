/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:04:50 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:04:50 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)d;
	if (d == s)
		i++;
	else if (d < s)
		while (i++ < n)
			*(char *)d++ = *(const char *)s++;
	else
		while (n-- > 0)
			((char *)d)[n] = ((const char *)s)[n];
	return (dest);
}
