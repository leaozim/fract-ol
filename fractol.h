/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:53:40 by lade-lim          #+#    #+#             */
/*   Updated: 2022/09/09 18:56:49 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "./my_libs/ft_libft/libft.h"	
# include "./my_libs/ft_printf/ft_printf.h"
# include "keysym.h"


#include <stdio.h>

# define MANDELBROT 1
# define JULIA 2

# define WIDTH 600
# define HEIGHT 600

#define ERRO0 "Invalid number of parameters."
#define ERRO1 "Usage: ./fractol (Julia / Mandelbrot)"
#define ERRO2 "Is not a valid fractal name."

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	void	*addr;
}	t_mlx;

typedef struct s_fractol
{
	int		x;
	int		y;
	int		set;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	double	zmax;
	double	zmin;
	double	cmax;
	double	cmin;
	double	kmax;
	double	kmin;
	double	cent_min;
	double	cent_max;
	int		max_iterations;
	t_mlx	w_data;
}	t_fractol;

int			main(int argc, char **argv);
void		init_structs(t_fractol *data, int argc, char **argv);
void		init_window(t_fractol *f);
void		init_image(t_fractol *frac);
void		redraw_image(t_fractol *f);
int			close_win(t_fractol *f);
int			keyboard_events(int key, t_fractol *f);
void		set_color_frac(t_fractol *frac, int n);
int			set_color(t_fractol *frac, int n);
void		my_mlx_pixel_put(t_fractol *frac, int n);
int			draw_fractol(t_fractol *frac);
int			mandelbrot(t_fractol *frac);
int			julia(t_fractol *frac);
int			check_fractol(t_fractol *frac, int argc, char **argv);
double		ft_atof(char *str);
static void	init_julia(t_fractol *frac, int argc, char **argv);
int			mouse_event(int keysys, int x, int y, t_fractol *win);
void		fractol_move(int key, t_fractol *frac);
void		menu(t_fractol *v);

#endif