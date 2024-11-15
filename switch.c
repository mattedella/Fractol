/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:20:57 by mdella-r          #+#    #+#             */
/*   Updated: 2023/12/18 14:32:04 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_to_mandelbrot(t_gdata *data)
{
	if (data->f == NULL)
		data->previous_range = 0;
	data->f = &apply_mandelbrot;
	data->center.r = data->previous_center.r;
	data->center.i = data->previous_center.i;
	if (data->previous_range == 0)
		set_roi_range(data);
	else
		data->roi_range = data->previous_range;
	data->max_iter = data->previous_max_iter;
}

void	switch_to_julia(t_gdata *data, t_wdata *win_data)
{
	t_dcoord	mouse_complex;
	int			mouse_pos_x;
	int			mouse_pos_y;

	mlx_mouse_get_pos(win_data->mlx, win_data->win, &mouse_pos_x, &mouse_pos_y);
	data->julia_c.r = JULIA_C_R;
	data->julia_c.i = JULIA_C_I;
	if (data->f == &apply_mandelbrot)
	{
		mouse_complex.r = data->center.r + ((mouse_pos_x - WIN_WIDTH / 2)
				* data->roi_range / WIN_WIDTH);
		mouse_complex.i = - (data->center.i + ((mouse_pos_y - WIN_HEIGHT / 2)
					* data->roi_range / WIN_HEIGHT));
		data->julia_c = mouse_complex;
	}
	data->f = &apply_julia;
	data->previous_center = data->center;
	data->previous_range = data->roi_range;
	data->previous_max_iter = data->max_iter;
	data->center.r = 0;
	data->center.i = 0;
	data->roi_range = STARTING_ROI_JULIA;
	data->max_iter = STARTING_MAX_ITER;
}

void	switch_to_ship(t_gdata *data)
{
	if (data->f == NULL)
		data->previous_range = 0;
	data->f = &apply_ship;
	data->center.r = data->previous_center.r;
	data->center.i = data->previous_center.i;
	if (data->previous_range == 0)
		set_roi_range(data);
	else
		data->roi_range = data->previous_range;
	data->max_iter = data->previous_max_iter;
}

void	set_roi_range(t_gdata *data)
{
	if (data->f == NULL)
	{
		data->roi_range = 1;
		return ;
	}
	if (WIN_WIDTH > WIN_HEIGHT)
	{
		if (data->f == &apply_mandelbrot || data->f == NULL)
			data->roi_range = STARTING_ROI_MAND * WIN_WIDTH / WIN_HEIGHT;
		else if (data->f == &apply_julia)
			data->roi_range = STARTING_ROI_JULIA * WIN_WIDTH / WIN_HEIGHT;
	}
	else
	{
		if (data->f == &apply_mandelbrot || data->f == NULL)
			data->roi_range = STARTING_ROI_MAND * WIN_HEIGHT / WIN_WIDTH;
		else if (data->f == &apply_julia)
			data->roi_range = STARTING_ROI_JULIA * WIN_HEIGHT / WIN_WIDTH;
	}
	if (data->f == &apply_mandelbrot)
		data->center.r = -0.75;
	data->previous_range = data->roi_range;
}
