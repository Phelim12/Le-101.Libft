/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_imaxtoa_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 19:00:17 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 19:00:17 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa_base(intmax_t nbr, char *base)
{
	int		base_size;
	char	*str;
	int		neg;
	int		i;

	if (nbr == 0)
		return (ft_strdup("0"));
	i = 0;
	base_size = ft_strlen(base);
	str = ft_strnew(ft_ilen_base(nbr, base_size) + 1);
	neg = FT_NEG(nbr);
	while (nbr)
	{
		str[i++] = base[nbr % base_size];
		nbr = nbr / base_size;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
