/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 18:35:42 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 18:35:42 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int nbr, char *base)
{
	int		i;
	int		neg;
	int		base_size;
	char	*str;

	if (nbr == 0)
		return (ft_strdup("0"));
	i = 0;
	base_size = ft_strlen(base);
	str = ft_strnew(ft_ilen_base(nbr, base_size) + 1);
	neg = FT_NEG(nbr);
	while (nbr)
	{
		str[i++] = base[FT_ABS(nbr % base_size)];
		nbr = nbr / base_size;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
