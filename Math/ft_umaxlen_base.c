/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_umaxlen_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 15:15:05 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:15:05 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_umaxlen_base(uintmax_t n, int base)
{
	int	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}
