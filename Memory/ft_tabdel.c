/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 19:19:43 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 19:19:43 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char **tab)
{
	int	cur;

	cur = -1;
	if (!tab)
		return ;
	while (tab[++cur])
		ft_strdel(&tab[cur]);
	free(tab);
	tab = NULL;
}
