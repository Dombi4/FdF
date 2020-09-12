/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:16:37 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:17:16 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dest;
	unsigned char *sorc;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (n--)
	{
		*dest = *sorc;
		dest++;
		sorc++;
	}
	return (dst);
}
