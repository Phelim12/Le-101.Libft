/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrsub.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 14:51:26 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 14:51:26 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*str;

	if (!s)
		return ((wchar_t *)s);
	str = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (!str)
		return (NULL);
	while (start--)
		s++;
	ft_wstrncpy(str, s, len);
	str[len] = '\0';
	return (str);
}
