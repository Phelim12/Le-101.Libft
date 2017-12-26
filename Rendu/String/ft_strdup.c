/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:06:28 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:06:28 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *d;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}
