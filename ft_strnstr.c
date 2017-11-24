/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:07:54 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:07:54 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	size_t	s_n;
	int		a;
	int		b;

	a = 0;
	if (*to_find == '\0' || !to_find)
		return ((char *)s);
	while (s[a] && n)
	{
		b = 0;
		s_n = n;
		while (s[a + b] == to_find[b] && s[a + b] && s_n--)
			b++;
		if (to_find[b] == '\0')
			return ((char *)s + a);
		a++;
		n--;
	}
	return (NULL);
}
