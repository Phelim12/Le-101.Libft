/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:39:11 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/10 15:34:53 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *d, const char *s)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (d[a])
		a++;
	while (s[b])
	{
		d[b + a] = s[b];
		b++;
	}
	d[a + b] = '\0';
	return (d);
}
