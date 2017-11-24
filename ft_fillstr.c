/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fillstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:02:02 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:02:02 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillstr(char *s, char c)
{
	char	*new_s;
	int		a;

	a = 0;
	new_s = (char *)malloc(sizeof(char) * (ft_count_len(s, c) + 1));
	while (*s != c && *s != '\0')
		new_s[a++] = *s++;
	new_s[a] = '\0';
	return (new_s);
}
