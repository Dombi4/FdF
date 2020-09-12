/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:13:19 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:13:21 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
		{
			while (len)
			{
				dst[i] = '\0';
				i++;
				len--;
			}
			return (dst);
		}
		len--;
		i++;
	}
	return (dst);
}
