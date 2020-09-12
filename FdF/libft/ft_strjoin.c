/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:14:05 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:14:08 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	new = ft_strnew(i);
	if (new == 0)
		return (NULL);
	while (s1[j] != '\0')
	{
		new[j] = s1[j];
		j++;
	}
	while (*s2)
	{
		new[j] = *s2;
		s2++;
		j++;
	}
	return (new);
}
