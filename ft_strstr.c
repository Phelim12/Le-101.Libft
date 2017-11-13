/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:03:52 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/10 12:21:33 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	int a;
	int b;

	a = 0;
	if (*to_find == '\0' || !to_find)
		return ((char *)s);
	while (s[a])
	{
		b = 0;
		while (s[a + b] == to_find[b] && s[a + b])
			b++;
		if (to_find[b] == '\0')
			return ((char *)s + a);
		a++;
	}
	return (NULL);
}
