/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:02:09 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/09 19:20:37 by clcreuso         ###   ########.fr       */
/*                                                                            */
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
