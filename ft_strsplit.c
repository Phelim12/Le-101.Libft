/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <clcreuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:52:18 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/13 15:41:19 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		a;

	a = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ft_count_words(s, 0, c));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			tab[a++] = ft_fillstr((char *)s, c);
		while (*s != c && *s != '\0')
			s++;
	}
	tab[a] = NULL;
	return (tab);
}
