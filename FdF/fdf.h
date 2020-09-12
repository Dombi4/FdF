/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:19:32 by tmorgana          #+#    #+#             */
/*   Updated: 2020/08/15 00:22:40 by tmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# define WID 1300

typedef struct	s_alst
{
	float		x;
	float		y;
	float		z;
	int			col;
}				t_alst;

typedef struct	s_blst
{
	t_alst		**point;
	int			hig;
	int			wit;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			line_size;
	int			endian;
	int			cx;
	int			cy;
	int			zm;
	float		x;
	float		z;
	float		y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			colx1;
	int			coly1;
	int			my;
	int			mx;
	char		**str;
}				t_blst;

int				main(int argc, char **argv);
void			ft_draw(t_blst *fdf);
void			ft_newdata(t_blst *fdf);
int				ft_atoi_base(const char *str, int str_base);
int				ft_key(int key, t_blst *fdf);
void			ft_rotat(t_blst *fdf, int i, int j, int key);
void			ft_iso(t_blst *fdf);
int				ft_color(char *wrd);
int				ft_atoi_base(const char *str, int str_base);
int				ft_mouse(int button, int x, int y, t_blst *fdf);
void			ft_openwindow(t_blst *fdf);
int				ft_read(int fd);
void			ft_strtoi(t_blst *fdf);
void			ft_horizont(t_blst *fdf, int i, int j);
void			ft_vertic(t_blst *fdf, int i, int j);
void			ft_ndata(t_blst *fdf);
void			ft_ndraw(t_blst *fdf);
void			ft_iterat(int key, t_blst *fdf);
int				ft_closemap(void *fdf);
void			ft_bresenham(t_blst *fdf);
void			ft_horizontal(t_blst *fdf);
void			ft_vertical(t_blst *fdf);
void			ft_swapint(t_blst *fdf);
void			ft_valid(char *str);
char			**ft_readmap(int fd);
int				ft_base(int c, int base);

#endif
