/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:05:52 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:05:52 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *d, const char *s)
{
	char *ret;

	ret = d;
	d += ft_strlen(d);
	while (*s)
		*d++ = *s++;
	*d = 0;
	return (ret);
}
