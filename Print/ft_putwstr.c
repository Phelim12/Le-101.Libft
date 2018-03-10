/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 20:34:57 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 20:34:57 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *wstr)
{
	int ret;
	int cur;

	ret = 0;
	cur = 0;
	while (wstr[cur])
	{
		ret += ft_putwchar(wstr[cur]);
		cur++;
	}
	return (ret);
}
