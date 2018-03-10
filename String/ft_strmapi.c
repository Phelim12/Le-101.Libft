/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:07:17 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:07:17 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*new;

	a = 0;
	if (!s)
		return ((char *)s);
	new = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!new)
		return (NULL);
	while (s[a])
	{
		new[a] = f(a, s[a]);
		a++;
	}
	new[a] = '\0';
	return (new);
}
