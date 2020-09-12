/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:53:37 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:26:51 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_strtoi(t_blst *fdf)
{
	char	**wrd;
	int		x;
	int		y;

	y = 0;
	fdf->point = (t_alst **)malloc(sizeof(t_alst) * fdf->hig);
	while (fdf->str[y] != '\0')
	{
		x = 0;
		wrd = ft_strsplit(fdf->str[y], ' ');
		while (wrd[fdf->wit] != '\0')
			fdf->wit++;
		fdf->point[y] = (t_alst *)malloc(sizeof(t_alst) * fdf->wit);
		while (wrd[x] != '\0')
		{
			fdf->point[y][x].x = x;
			fdf->point[y][x].y = y;
			fdf->point[y][x].z = ft_atoi(wrd[x]);
			fdf->point[y][x].col = ft_color(wrd[x]);
			free(wrd[x]);
			x++;
		}
		free(wrd);
		y++;
	}
}

void	ft_valid(char *str)
{
	int i;
	int m;
	int n;

	i = 0;
	m = 0;
	n = 0;
	while (str[i] != '\0')
	{
		n = 0;
		while (str[i] != '\n' && str[i] != '\0')
		{
			if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n' ||
			str[i + 1] == '\0'))
				n++;
			i++;
		}
		if (m == 0)
			m = n;
		if (m != n)
			exit(0);
		if (str[i] == '\n')
			i++;
	}
}

char	**ft_readmap(int fd)
{
	char	buf[10001];
	char	*tmp;
	int		k;
	char	*arr;
	char	**str;

	arr = ft_strnew(0);
	while ((k = read(fd, buf, 10000)) > 0)
	{
		buf[k] = '\0';
		tmp = arr;
		arr = ft_strjoin(arr, buf);
		free(tmp);
	}
	if (arr[0] == '\0')
	{
		ft_putstr("usage: ./fdf inputFile.fdf");
		exit(0);
	}
	ft_valid(arr);
	str = ft_strsplit(arr, '\n');
	free(arr);
	return (str);
}

int		ft_read(int fd)
{
	t_blst	*fdf;

	fdf = (t_blst *)malloc(sizeof(t_blst));
	fdf->hig = 0;
	fdf->wit = 0;
	fdf->str = ft_readmap(fd);
	while (fdf->str[fdf->hig] != '\0')
		fdf->hig++;
	ft_strtoi(fdf);
	ft_ndata(fdf);
	ft_openwindow(fdf);
	return (0);
}
