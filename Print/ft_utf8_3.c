/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utf8_3.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 16:35:10 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 16:35:10 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_utf8_3(wchar_t w, int fd)
{
	unsigned char	*tmp;
	int				ret;

	ret = 0;
	tmp = (unsigned char *)ft_strnew(3);
	tmp[0] = ((w >> 12) | 224);
	if (w >= 2048 && w <= 4095)
		tmp[1] = ((w >> 6) | 160);
	else if (w >= 53248 && w <= 55295)
		tmp[1] = (((w >> 6) ^ 832) | 128);
	else
		tmp[1] = ((((w >> 6) ^ ((w >> 12) << 6))) | 128);
	tmp[2] = ((w ^ ((w >> 6) << 6)) | 128);
	while (tmp[ret])
		write(fd, &tmp[ret++], 1);
	free(tmp);
	return (ret);
}
