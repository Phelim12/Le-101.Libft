/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_number.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 19:49:07 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 19:49:07 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_number(const char *str)
{
	int cur;

	cur = 0;
	if (!(ft_strchr("+-", str[cur])) && !(ft_isdigit(str[cur])))
		return (0);
	if (ft_strchr("+-", str[cur]) && !(ft_isdigit(str[cur + 1])))
		return (0);
	while (str[++cur])
		if (!(ft_isdigit(str[cur])))
			return (0);
	return (1);
}
