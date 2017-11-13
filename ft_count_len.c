/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <clcreuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:50:10 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/13 15:35:36 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_len(const char *s, char c)
{
	int a;

	a = 0;
	while (s[a] != c && s[a] != '\0')
		a++;
	return (a);
}
