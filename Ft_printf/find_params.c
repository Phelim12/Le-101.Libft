/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_params.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 19:51:08 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 19:51:08 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_wildcard(t_params *ptr)
{
	if (ptr->size_width < 0)
	{
		ptr->flag_less = TRUE;
		ptr->size_width = FT_ABS(ptr->size_width);
	}
	if (ptr->size_precision < 0)
	{
		ptr->flag_point = FALSE;
		ptr->size_precision = -1;
	}
}

void	ft_find_flags(char specs, t_params *ptr)
{
	if (specs == '#')
		ptr->flag_hashtag = TRUE;
	if (specs == '-')
		ptr->flag_less = TRUE;
	if (specs == '+')
		ptr->flag_more = TRUE;
	if (specs == ' ')
		ptr->flag_space = TRUE;
	if (specs == '0' && ptr->flag_point == FALSE)
		ptr->flag_zero = TRUE;
	if (specs == '.')
		ptr->flag_point++;
}

int		ft_find_number(va_list ap, char *specs, int *nbr)
{
	int		cursor;
	int		ret;
	char	*nb;

	ret = 0;
	cursor = 0;
	nb = ft_strnew(32);
	if (*specs == '*')
	{
		free(nb);
		*nbr = va_arg(ap, int);
		return (0);
	}
	while (ft_isdigit(*(specs + cursor)))
		cursor++;
	ret = (cursor - 1);
	while (--cursor >= 0)
		nb[cursor] = *(specs + cursor);
	*nbr = ft_atoi(nb);
	free(nb);
	return (ret);
}

int		ft_find_size(char *specs, t_params *ptr)
{
	if (*specs == 'l' && *(specs + 1) == 'l')
		ptr->size_type = 'L';
	else if (*specs == 'h' && *(specs + 1) == 'h')
		ptr->size_type = 'H';
	else if (ft_strchr("jz", *(specs - 1)) && ft_strchr("jzhl", *(specs)))
		ptr->size_type = ptr->size_type;
	else
		ptr->size_type = *specs;
	if (ft_isupper(ptr->size_type))
		return (1);
	return (0);
}

int		ft_find_params(va_list ap, char *specs, t_params *ptr)
{
	int ret;

	ret = 0;
	if (ft_strchr("#-+ 0.", *specs))
		ft_find_flags(*specs, ptr);
	else if ((ft_isdigit(*specs) || *specs == '*') && ptr->flag_point == FALSE)
		ret = ft_find_number(ap, specs, &ptr->size_width);
	else if ((ft_isdigit(*specs) || *specs == '*') && *(specs - 1) == '.')
		ret = ft_find_number(ap, specs, &ptr->size_precision);
	else if (ft_strchr("hjlz", *specs))
		ret = ft_find_size(specs, ptr);
	if (*specs == '*')
		ft_modify_wildcard(ptr);
	if (ptr->flag_zero == TRUE && ptr->flag_less == TRUE)
		ptr->flag_zero = FALSE;
	if (ptr->size_precision > 0 && ptr->flag_zero == TRUE)
		ptr->flag_zero = FALSE;
	if (ptr->flag_point > 1)
		ptr->size_precision = 0;
	return (ret);
}
