/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:12:29 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:12:30 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	findmin(char const *s, size_t min)
{
	while ((s[min] == ' ' || s[min] == '\n' || s[min] == '\t') && *s)
		min++;
	return (min);
}

static size_t	findmax(char const *s, size_t max)
{
	max--;
	while ((s[max] == ' ' || s[max] == '\n' || s[max] == '\t') && *s)
		max--;
	return (max);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	len;
	size_t	a;

	if (s == 0)
		return (NULL);
	a = 0;
	len = ft_strlen((char *)s);
	i = findmin(s, 0);
	len = findmax(s, len) + 1;
	if (len < i)
		len = i;
	new = (char *)malloc(sizeof(char) * (len - i + 1));
	if (new == 0)
		return (NULL);
	while (i != len)
	{
		new[a] = s[i];
		i++;
		a++;
	}
	new[a] = '\0';
	return (new);
}
