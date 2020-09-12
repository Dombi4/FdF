/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:13:49 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:13:51 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	len;
	size_t	i;

	if (s == 0)
		return (0);
	len = ft_strlen(s);
	i = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (0);
	while (len > i)
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
