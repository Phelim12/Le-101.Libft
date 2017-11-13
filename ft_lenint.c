/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <clcreuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:30:51 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/13 15:35:38 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenint(int n)
{
	int	ret;

	ret = 1;
	if (n < 0)
		ret++;
	while ((n) && (n /= 10))
		ret++;
	return (ret);
}
