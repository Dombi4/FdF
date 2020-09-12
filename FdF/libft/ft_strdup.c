/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:14:50 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:14:53 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		len;
	char	*copy;

	len = 0;
	while (src[len] != '\0')
		len++;
	copy = (char*)malloc(sizeof(*src) * (len + 1));
	if (copy == NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		copy[len] = src[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}
