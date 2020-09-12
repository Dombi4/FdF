/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:49:13 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:42:09 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_ndata(t_blst *fdf)
{
	fdf->zm = WID * 0.5 / (fdf->hig - 1);
	if (fdf->hig < fdf->wit)
		fdf->zm = WID * 0.5 / (fdf->wit - 1);
	fdf->cx = (WID / 2) - (fdf->wit * fdf->zm / 2);
	fdf->cy = (WID / 2) - (fdf->hig * fdf->zm / 2);
	fdf->my = fdf->hig / 2;
	fdf->mx = fdf->wit / 2;
}

void	ft_horizont(t_blst *fdf, int i, int j)
{
	fdf->x1 = fdf->point[i][j].x * fdf->zm + fdf->cx;
	fdf->y1 = fdf->point[i][j].y * fdf->zm + fdf->cy;
	fdf->x2 = fdf->point[i + 1][j].x * fdf->zm + fdf->cx;
	fdf->y2 = fdf->point[i + 1][j].y * fdf->zm + fdf->cy;
	fdf->colx1 = fdf->point[i][j].col;
	ft_bresenham(fdf);
}

void	ft_vertic(t_blst *fdf, int i, int j)
{
	fdf->x1 = fdf->point[i][j].x * fdf->zm + fdf->cx;
	fdf->y1 = fdf->point[i][j].y * fdf->zm + fdf->cy;
	fdf->x2 = fdf->point[i][j + 1].x * fdf->zm + fdf->cx;
	fdf->y2 = fdf->point[i][j + 1].y * fdf->zm + fdf->cy;
	fdf->coly1 = fdf->point[i][j].col;
	ft_bresenham(fdf);
}
