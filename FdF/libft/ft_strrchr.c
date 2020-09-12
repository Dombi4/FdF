/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:12:57 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:12:59 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;

	s2 = 0;
	while (*s)
	{
		if (*s == (char)c)
			s2 = (char *)s;
		s++;
	}
	if (*s == (char)c)
		s2 = (char *)s;
	if (s2 == 0)
		return (NULL);
	else
		return (s2);
}
