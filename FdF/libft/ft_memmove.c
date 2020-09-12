/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:16:27 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:16:30 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sorc;

	dest = (char *)dst;
	sorc = (const char *)src;
	if (dst == src)
		return (NULL);
	if (dst < src)
	{
		while (len--)
		{
			*dest = *sorc;
			dest++;
			sorc++;
		}
	}
	else
	{
		while (len--)
			dest[len] = sorc[len];
	}
	return (dst);
}
