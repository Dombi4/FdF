/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:50:21 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:30:55 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_iso(t_blst *fdf)
{
	int prev_x;
	int prev_y;
	int i;
	int j;

	i = 0;
	while (i < fdf->hig)
	{
		j = 0;
		while (j < fdf->wit)
		{
			prev_x = fdf->point[i][j].x;
			prev_y = fdf->point[i][j].y;
			fdf->point[i][j].x = (prev_x - prev_y) * cos(0.5)
			+ fdf->mx;
			fdf->point[i][j].y = -(fdf->point[i][j].z) +
			(prev_x + prev_y) * sin(0.5) + fdf->my;
			j++;
		}
		i++;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->img_data, WID * WID * 4);
	ft_draw(fdf);
}

void	ft_rotat(t_blst *fdf, int i, int j, int key)
{
	float r;

	r = 0.174533;
	fdf->x = fdf->point[i][j].x - fdf->mx;
	fdf->y = fdf->point[i][j].y - fdf->my;
	fdf->z = fdf->point[i][j].z;
	if (key == 125 || key == 123 || key == 65)
		r = -0.174533;
	if (key == 126 || key == 125)
	{
		fdf->point[i][j].y = fdf->my + fdf->y * cos(r) - fdf->z * sin(r);
		fdf->point[i][j].z = fdf->y * sin(r) + fdf->z * cos(r);
	}
	if (key == 124 || key == 123)
	{
		fdf->point[i][j].x = fdf->mx + fdf->x * cos(r) + fdf->z * sin(r);
		fdf->point[i][j].z = -fdf->x * sin(r) + fdf->z * cos(r);
	}
	if (key == 82 || key == 65)
	{
		fdf->point[i][j].x = fdf->mx + fdf->x * cos(r) - fdf->y * sin(r);
		fdf->point[i][j].y = fdf->my + fdf->x * sin(r) + fdf->y * cos(r);
	}
}

void	ft_iterat(int key, t_blst *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf->hig)
	{
		j = -1;
		while (++j < fdf->wit)
		{
			if (key == 1)
				fdf->point[i][j].y += 1;
			if (key == 13)
				fdf->point[i][j].y -= 1;
			if (key == 2)
				fdf->point[i][j].x += 1;
			if (key == 0)
				fdf->point[i][j].x -= 1;
			ft_rotat(fdf, i, j, key);
		}
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->img_data, WID * WID * 4);
	ft_draw(fdf);
}

int		ft_key(int key, t_blst *fdf)
{
	if (key == 126 || key == 124 || key == 82 || key == 125 ||
	key == 123 || key == 65 || key == 1 || key == 13 || key == 2
	|| key == 0 || key == 69)
		ft_iterat(key, fdf);
	if (key == 29)
		ft_ndraw(fdf);
	if (key == 49)
		ft_iso(fdf);
	if (key == 53)
		exit(0);
	return (0);
}

void	ft_ndraw(t_blst *fdf)
{
	int i;

	i = 0;
	while (i < fdf->hig)
	{
		free(fdf->point[i]);
		i++;
	}
	free(fdf->point);
	ft_strtoi(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->img_data, WID * WID * 4);
	ft_draw(fdf);
}
