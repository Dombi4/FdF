/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:09:13 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:09:17 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countnum(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strsub("-2147483648", 0, 12));
	len = ft_countnum(n);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (NULL);
	new[len] = '\0';
	len--;
	if (n < 0)
	{
		n = -n;
		new[i++] = '-';
	}
	while (len >= i)
	{
		new[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (new);
}
