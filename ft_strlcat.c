/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:37:48 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/13 18:23:35 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t		i;
	size_t		t1;
	size_t		t2;

	i = 0;
	t1 = ft_strlen(d);
	t2 = ft_strlen(s);
	if (n == 0)
		return (0);
	if (n - 1 <= t1)
		return (t2 + n);
	while (i++ < t1)
		d++;
	i--;
	while (i++ < n - 1)
		*d++ = *s++;
	*d = '\0';
	return (t1 + t2);
}
