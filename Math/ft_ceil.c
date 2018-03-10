/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ceil.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/10 18:34:19 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 18:34:19 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_ceil(float result)
{
	int		ret;

	ret = result;
	if (ret == result)
		return (ret);
	return (ret + 1);
}
