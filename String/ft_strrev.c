/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 15:45:38 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 15:45:38 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	swap;
	int		size;
	int		a;

	a = 0;
	size = ft_strlen(str);
	while (a < size / 2)
	{
		swap = str[size - (a + 1)];
		str[size - (a + 1)] = str[a];
		str[a] = swap;
		a++;
	}
	return (str);
}
