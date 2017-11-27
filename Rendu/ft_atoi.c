/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:01:26 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:01:26 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int		nb;
	int		neg;

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
