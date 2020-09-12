/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:13:05 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:13:06 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	int i;
	int j;
	int m;

	i = 0;
	while (str1[i] && n > 0)
	{
		m = n;
		j = 0;
		while (str2[j] == str1[i + j] && m--)
		{
			if (str2[j + 1] == '\0')
				return ((char *)str1 + i);
			j++;
		}
		i++;
		n--;
	}
	if (str2[0] == '\0')
		return ((char *)str1);
	return (NULL);
}
