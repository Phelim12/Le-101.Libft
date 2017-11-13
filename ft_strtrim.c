/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:48:01 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/13 15:41:06 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		a;
	int		b;
	int		c;

	c = 0;
	b = 0;
	if (!s)
		return ((char *)s);
	a = (ft_strlen((char *)s) - 1);
	while ((s[a] == ' ' || s[a] == '\t' || s[a] == '\n') && s[a])
		a--;
	while ((s[b] == ' ' || s[b] == '\t' || s[b] == '\n') && s[a])
		b++;
	new = malloc(sizeof(char) * ((a + 2) - b));
	if (!new)
		return (NULL);
	while (b <= a)
		new[c++] = s[b++];
	new[c] = '\0';
	return (new);
}
