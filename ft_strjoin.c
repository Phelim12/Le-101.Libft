/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:15:22 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/10 20:52:19 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		a;

	if (!s1 || !s2)
		return ((char *)s1);
	a = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	new = (char *)malloc(sizeof(char) + (a + 1));
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, (char *)s2);
	return (new);
}
