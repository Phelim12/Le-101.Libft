/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoimax.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 14:50:02 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 14:50:02 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoimax(const char *s)
{
	intmax_t	nb;
	int			neg;

	nb = 0;
	neg = 1;
	while (ft_isspace(*s) && *s != 0)
		s++;
	if (*s == 0)
		return (0);
	if (*s == '-')
		neg = 0;
	if (*s == '-' || *s == '+')
		s++;
	while (*s <= '9' && *s >= '0')
		nb = (nb * 10) + (*s++ - '0');
	if (neg == 0)
		return (-nb);
	return (nb);
}
