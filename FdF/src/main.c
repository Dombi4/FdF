/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:53:25 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/14 23:54:22 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>

int		ft_mouse(int kn, int x, int y, t_blst *fdf)
{
	(void)x;
	(void)y;
	if (kn == 5)
		fdf->zm += 5;
	if (kn == 4)
		if (fdf->zm - 5 > 0)
			fdf->zm = fdf->zm - 5;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->img_data, WID * WID * 4);
	ft_draw(fdf);
	return (0);
}

int		ft_closemap(void *fdf)
{
	(void)fdf;
	exit(0);
	return (0);
}

void	ft_openwindow(t_blst *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WID, WID, "mlx 42");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WID, WID);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
	&fdf->line_size, &fdf->endian);
	ft_draw(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, ft_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_closemap, fdf);
	mlx_mouse_hook(fdf->win_ptr, ft_mouse, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (argc == 1 || argc > 2)
	{
		if (argc != 2)
		{
			ft_putstr("usage: ./fdf inputFile.fdf");
			return (0);
		}
	}
	ft_read(fd);
	return (0);
}
