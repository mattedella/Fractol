/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:37:27 by mdella-r          #+#    #+#             */
/*   Updated: 2023/12/20 11:29:25 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_gdata *data)
{
	if (keycode == ESC_KEY)
		quit(0, data);
	else if (keycode == LEFT_ARROW || keycode == A_KEY)
		data->center.r -= data->roi_range * STEP_SIZE;
	else if (keycode == RIGHT_ARROW || keycode == D_KEY)
		data->center.r += data->roi_range * STEP_SIZE;
	else if (keycode == UP_ARROW || keycode == W_KEY)
		data->center.i -= data->roi_range * STEP_SIZE;
	else if (keycode == DOWN_ARROW || keycode == S_KEY)
		data->center.i += data->roi_range * STEP_SIZE;
	else if (keycode == SPACE_KEY)
		data->color_grad += 0.1;
	else if (keycode == B_KEY)
		switch_to_ship(data);
	else if (keycode == J_KEY)
		switch_to_julia(data, data->win_data);
	else if (keycode == M_KEY)
		switch_to_mandelbrot(data);
	else
		return (0);
	call_threads(data);
	return (0);
}

static void	zoom_in(t_dcoord *d, int x, int y, t_gdata *data)
{
	d->r = (x - WIN_WIDTH / 2) * (1 - ZOOM_FACTOR);
	d->i = (y - WIN_HEIGHT / 2) * (1 - ZOOM_FACTOR);
	data->roi_range /= ZOOM_FACTOR;
	if (data->max_iter < MAX_ITER)
		data->max_iter *= MAX_ITER_CHANGE_FACTOR;
	else
		data->max_iter = MAX_ITER;
}

static void	zoom_out(t_dcoord *d, int x, int y, t_gdata *data)
{
	d->r = (x - WIN_WIDTH / 2) * (1 - 1 / ZOOM_FACTOR);
	d->i = (y - WIN_HEIGHT / 2) * (1 - 1 / ZOOM_FACTOR);
	data->roi_range *= ZOOM_FACTOR;
	data->max_iter /= MAX_ITER_CHANGE_FACTOR;
}

int	mouse_hook(int button, int x, int y, t_gdata *data)
{
	t_dcoord		d;
	double			old_roi;

	old_roi = data->roi_range;
	if (button == 4)
		zoom_in(&d, x, y, data);
	else if (button == 5)
		zoom_out(&d, x, y, data);
	else
		return (0);
	data->center.r -= d.r * old_roi / WIN_WIDTH;
	data->center.i -= d.i * old_roi / WIN_HEIGHT;
	call_threads(data);
	return (0);
}
