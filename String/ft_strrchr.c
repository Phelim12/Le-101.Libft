/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:08:13 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:08:13 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char*) * ft_strlen(s));
	if (!s)
		return (NULL);
	ft_strcpy(str, s);
	i = ft_strlen(s);
	str += i;
	while ((int)i >= 0)
	{
		if (*str-- == c)
			return ((char*)s + i);
		i--;
	}
	return (NULL);
}
