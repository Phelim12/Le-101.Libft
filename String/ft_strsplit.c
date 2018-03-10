/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 22:08:21 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 22:08:21 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int nb_words;

	nb_words = 0;
	while (*s)
		if (*s++ == c)
			nb_words++;
	return (nb_words + 2);
}

static int	ft_lenchr(const char *s, char c)
{
	int a;

	a = 0;
	while (s[a] != c && s[a] != '\0')
		a++;
	return (a);
}

static char	*ft_fillstr(char *s, char c)
{
	char	*new_s;
	int		a;

	a = 0;
	new_s = ft_strnew(ft_lenchr(s, c));
	while (*s != c && *s != '\0')
		new_s[a++] = *s++;
	new_s[a] = '\0';
	return (new_s);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		a;

	a = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ft_count_words(s, c));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			tab[a++] = ft_fillstr((char *)s, c);
		while (*s != c && *s != '\0')
			s++;
	}
	tab[a] = NULL;
	return (tab);
}
