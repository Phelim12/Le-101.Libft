/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 18:34:07 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 18:34:07 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int cur;
	int ret;

	ret = 0;
	cur = 0;
	while (wstr[cur])
	{
		ret += ft_size_wchar(wstr[cur]);
		cur++;
	}
	return (ret);
}
