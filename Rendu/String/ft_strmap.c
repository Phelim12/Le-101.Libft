/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:07:13 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:07:13 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		a;
	char	*new;

	a = 0;
	if (!s)
		return ((char *)s);
	new = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!new)
		return (NULL);
	while (s[a])
	{
		new[a] = f(s[a]);
		a++;
	}
	new[a] = '\0';
	return (new);
}
