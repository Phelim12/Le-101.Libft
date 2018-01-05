/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utf8_2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 16:34:57 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 16:34:57 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_utf8_2(wchar_t w, int fd)
{
	unsigned char	*tmp;
	int				ret;

	ret = 0;
	tmp = (unsigned char *)ft_strnew(2);
	tmp[0] = ((w >> 6) | 192);
	tmp[1] = ((w ^ ((w >> 6) << 6)) | 128);
	while (tmp[ret])
		write(fd, &tmp[ret++], 1);
	free(tmp);
	return (ret);
}
