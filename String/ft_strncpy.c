/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:07:34 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:07:34 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *d, const char *s, size_t n)
{
	unsigned int a;

	a = 0;
	while (s[a] && a < n)
	{
		d[a] = s[a];
		a++;
	}
	while (a < n)
		d[a++] = '\0';
	return (d);
}
