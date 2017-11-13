/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:02:09 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/13 19:53:52 by clcreuso         ###   ########.fr       */
/*                                                                            */
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
