/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:44:46 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/31 13:45:27 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define WIN_WIDTH 1080
# define WIN_HEIGHT 1080
# define MAX_ITER 1000
# define ZOOM_FACTOR 1.15
# define MAX_ITER_CHANGE_FACTOR 1.009
# define STARTING_ROI_MAND 6
# define STARTING_ROI_JULIA 4
# define STARTING_MAX_ITER 900
# define JULIA_C_R 0.0
# define JULIA_C_I 0.0 
# define STEP_SIZE 0.01
# define N_THREADS 720
# define PI 3.14159265358979323846
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define B_KEY 98
# define J_KEY 106
# define M_KEY 109
# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define P_KEY 112
# define ESC_KEY 65307
# define SPACE_KEY 32
# define ERROR_ARG "use mandelbrot, julia or ship\n"

typedef struct s_double_coordinates
{
	double			r;
	double			i;
}					t_dcoord;

typedef struct s_int_coordinates
{
	unsigned short	r;
	unsigned short	i;
}					t_icoord;

typedef struct s_trgb
{
	double	r;
	double	g;
	double	b;
}				t_rgb;

typedef struct s_window_data
{
	void			*win;
	void			*img;
	void			*mlx;
	int				endian;
	int				bits_per_pixel;
	int				line_length;
	char			*addr;
}					t_wdata;

typedef struct s_general_data
{
	t_wdata			*win_data;
	t_dcoord		(*f)(t_dcoord, t_dcoord, struct s_general_data *);
	t_dcoord		center;
	t_dcoord		previous_center;
	t_dcoord		julia_c;
	double			roi_range;
	double			previous_range;
	double			max_iter;
	double			previous_max_iter;
	double			color_grad;
}					t_gdata;

typedef struct s_threads_data
{
	t_gdata			*data;
	unsigned short	start_y;
	unsigned short	end_y;
}					t_tdata;

t_dcoord	apply_mandelbrot(t_dcoord old, t_dcoord c, t_gdata *data);
t_dcoord	apply_julia(t_dcoord old, t_dcoord c, t_gdata *data);
t_dcoord	apply_ship(t_dcoord z, t_dcoord c, t_gdata *data);
int			key_hook(int keycode, t_gdata *data);
int			mouse_hook(int button, int x, int y, t_gdata *data);
int			quit(char id, t_gdata *data);
int			press_x(t_gdata *data);
int			ft_strcmp(char *s1, char *s2);
void		call_threads(t_gdata *data);
void		my_mlx_pixel_put(t_gdata *data, int x, int y,
				unsigned short intensity);
void		switch_to_mandelbrot(t_gdata *data);
void		switch_to_julia(t_gdata *data, t_wdata *win_data);
void		switch_to_ship(t_gdata *data);
void		set_roi_range(t_gdata *data);
double		atod(char *argv);
#endif