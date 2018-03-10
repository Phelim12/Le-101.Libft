/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:05:02 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:05:02 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(wchar_t w)
{
	if (w >= 0 && w <= 127)
		return (ft_utf8_1(w, 1));
	else if (w >= 128 && w <= 255)
		return (write(1, &w, 1));
	else if (w >= 256 && w <= 2047)
		return (ft_utf8_2(w, 1));
	else if (w >= 2048 && w <= 65535)
		return (ft_utf8_3(w, 1));
	else if (w >= 65536 && w <= 2097151)
		return (ft_utf8_4(w, 1));
	return (0);
}
