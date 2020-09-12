/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:11:30 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:11:33 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *st;

	st = (unsigned char *)s;
	while (n--)
	{
		if (*st == (unsigned char)c)
			return (st);
		st++;
	}
	return (NULL);
}
