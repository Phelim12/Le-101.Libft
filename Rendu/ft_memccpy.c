/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:04:28 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:04:28 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)d++ = *(unsigned char *)s;
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((unsigned char *)d);
	}
	return (NULL);
}
