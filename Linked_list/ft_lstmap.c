/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 15:35:21 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:35:21 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;

	if (!lst)
		return (NULL);
	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	elem = f(lst);
	elem->next = ft_lstmap(lst->next, f);
	return (elem);
}
