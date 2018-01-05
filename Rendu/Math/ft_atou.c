/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atou.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 17:10:37 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 17:10:37 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atou(const char *s)
{
	unsigned int nb;

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
