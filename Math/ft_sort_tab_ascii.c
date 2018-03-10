/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_tab_ascii.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 18:50:06 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 18:50:06 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_tab_ascii(char ***av)
{
	char	*swap;
	int		a;
	int		b;

	a = -1;
	while ((*av)[++a])
	{
		b = -1;
		while ((*av)[++b])
			if (ft_strcmp((*av)[a], (*av)[b]) < 0)
			{
				swap = (*av)[a];
				(*av)[a] = (*av)[b];
				(*av)[b] = swap;
			}
	}
}
