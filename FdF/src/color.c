/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:48:17 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:41:46 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_base(int c, int base)
{
	char	*str;
	char	*strup;
	int		i;

	str = "0123456789abcdef";
	strup = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == strup[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int	nb;
	int negatif;
	int i;

	nb = 0;
	negatif = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == ' ' || str[i] == '\n'
	|| str[i] == 't' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = 1;
		i++;
	}
	while (ft_base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + ft_base(str[i], str_base);
		i++;
	}
	if (negatif)
		return (-nb);
	return (nb);
}

int		ft_color(char *wrd)
{
	int	i;
	int color;

	if (ft_strchr(wrd, ',') == NULL)
		return (0xFFFF00);
	i = 0;
	while (wrd[i] != 'x')
		i++;
	i++;
	color = ft_atoi_base(&wrd[i], 16);
	return (color);
}
