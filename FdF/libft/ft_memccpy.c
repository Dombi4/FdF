/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:11:25 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:11:28 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	char		*dest;
	const char	*sorc;

	dest = dst;
	sorc = src;
	while (n--)
	{
		*dest = *sorc;
		dest++;
		if (*sorc == (char)c)
			return (dest++);
		sorc++;
	}
	return (NULL);
}
