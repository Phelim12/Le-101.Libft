/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoumax.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 14:54:39 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 14:54:39 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_atoumax(const char *s)
{
	uintmax_t nb;

	nb = 0;
	while (ft_isspace(*s) && *s != 0)
		s++;
	if (*s == 0)
		return (0);
	if (*s == '+')
		s++;
	while (*s <= '9' && *s >= '0')
		nb = (nb * 10) + (*s++ - '0');
	return (nb);
}
