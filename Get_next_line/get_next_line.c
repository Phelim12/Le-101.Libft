/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:52:35 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:52:35 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read_file(char **str, int fd)
{
	char	*sample;
	char	*tmp;
	int		ret;

	if (!(sample = ft_strnew(BUFF_SIZE + 1)))
		return (0);
	ret = read(fd, sample, BUFF_SIZE);
	if (ret > 0)
	{
		sample[ret] = '\0';
		tmp = ft_strjoin(*str, sample);
		free(*str);
		*str = tmp;
	}
	free(sample);
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static char	*str = NULL;
	char		*save;
	int			ret;

	if ((fd < 0 || line == NULL || read(fd, str, 0) < 0) ||
	(!str && !(str = ft_strnew(0))))
		return (-1);
	while (!(ft_strchr(str, '\n')))
	{
		ret = ft_read_file(&str, fd);
		if ((ret == 0) && !(ft_strlen(str)))
			return (0);
		if (ret == 0)
			str = ft_strjoin(str, "\n");
		if (ret < 0)
			return (-1);
	}
	if (ft_strchr(str, '\n'))
		save = ft_strdup(ft_strchr(str, '\n'));
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(save));
	ft_strdel(&str);
	if (save && (save + 1)[0] != 0)
		str = ft_strdup(save + 1);
	ft_strdel(&save);
	return (1);
}
