/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar_fd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:05:06 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:05:06 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar_fd(wchar_t w, int fd)
{
	if (w >= 0 && w <= 127)
		return (ft_utf8_1(w, fd));
	else if (w >= 128 && w <= 2047)
		return (ft_utf8_2(w, fd));
	else if (w >= 2048 && w <= 65535)
		return (ft_utf8_3(w, fd));
	else if (w >= 65536 && w <= 2097151)
		return (ft_utf8_4(w, fd));
	return (0);
}
