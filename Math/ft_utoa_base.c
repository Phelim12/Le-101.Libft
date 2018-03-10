/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 18:43:17 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 18:43:17 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned int nbr, char *base)
{
	int		i;
	int		base_size;
	char	*str;

	if (nbr == 0)
		return (ft_strdup("0"));
	i = 0;
	base_size = ft_strlen(base);
	str = ft_strnew(ft_ulen_base(nbr, base_size) + 1);
	while (nbr)
	{
		str[i++] = base[nbr % base_size];
		nbr = nbr / base_size;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
