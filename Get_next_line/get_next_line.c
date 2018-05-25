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

static int	ft_strdel_special(char **as, int ret)
{
	if (!as)
		return (ret);
	free(*as);
	*as = NULL;
	return (ret);
}

static char	*ft_strjoin_special(char *str)
{
	char *tmp;
	char *ret;

	tmp = ft_strdup(str);
	ft_strdel(&str);
	ret = ft_strjoin(tmp, "\n");
	ft_strdel(&tmp);
	return (ret);
}

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
		ft_strdel(str);
		*str = tmp;
	}
	ft_strdel(&sample);
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static char	*str = NULL;
	char		*save;
	int			ret;

	save = NULL;
	if ((fd < 0 || line == NULL || read(fd, str, 0) < 0) ||
		(!str && !(str = ft_strnew(0))))
		return (ft_strdel_special(&str, -1));
	while (!(ft_strchr(str, '\n')))
	{
		ret = ft_read_file(&str, fd);
		if ((ret == 0) && !(ft_strlen(str)))
			return (ft_strdel_special(&str, 0));
		if (ret == 0)
			str = ft_strjoin_special(str);
		if (ret < 0)
			return (-1);
	}
	if (ft_strchr(str, '\n'))
		save = ft_strdup(ft_strchr(str, '\n'));
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(save));
	ft_strdel(&str);
	if (save && (save + 1)[0] != 0)
		str = ft_strdup(save + 1);
	return (ft_strdel_special(&save, 1));
}
