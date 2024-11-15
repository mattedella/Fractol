/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:35:39 by mdella-r          #+#    #+#             */
/*   Updated: 2024/01/23 12:29:49 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned short	iterate(t_dcoord pix, t_gdata *data)
{
	t_dcoord		new;
	unsigned short	i;
	unsigned short	max_iter;

	t_dcoord (*f)(t_dcoord, t_dcoord, t_gdata *);
	new.r = 0;
	new.i = 0;
	max_iter = data->max_iter;
	f = data->f;
	i = -1;
	while (++i < max_iter && (new.r * new.r + new.i * new.i) <= 4)
		new = f(new, pix, data);
	return (i);
}

static void	render(t_icoord diff, t_tdata *threads_data, t_dcoord pix,
		unsigned short biggest)
{
	t_dcoord		adj_pix;

	adj_pix.r = threads_data->data->center.r + ((pix.r - WIN_WIDTH / 2)
			- diff.r) * threads_data->data->roi_range / biggest;
	adj_pix.i = threads_data->data->center.i + ((pix.i - WIN_HEIGHT / 2)
			- diff.i) * threads_data->data->roi_range / biggest;
	my_mlx_pixel_put(threads_data->data, pix.r, pix.i, iterate(adj_pix,
			threads_data->data));
}

static void	*render_fractal(void *data)
{
	t_dcoord		pix;
	unsigned short	biggest;
	t_tdata			*threads_data;
	t_icoord		diff;

	threads_data = (t_tdata *)data;
	biggest = (WIN_WIDTH > WIN_HEIGHT) * WIN_WIDTH + (WIN_WIDTH <= WIN_HEIGHT)
		* WIN_HEIGHT;
	diff.r = ((biggest - WIN_WIDTH) / 2) * (WIN_WIDTH > WIN_HEIGHT);
	diff.i = ((biggest - WIN_HEIGHT) / 2) * (WIN_HEIGHT > WIN_WIDTH);
	pix.r = -1;
	pix.i = threads_data->start_y - 1;
	while (++pix.i < threads_data->end_y)
	{
		while (++pix.r < WIN_WIDTH)
			render(diff, threads_data, pix, biggest);
		pix.r = -1;
	}
	return (NULL);
}

void	call_threads(t_gdata *data)
{
	t_tdata			thread_args[N_THREADS];
	pthread_t		thread_ids[N_THREADS];
	unsigned short	i;

	i = -1;
	while (++i < N_THREADS)
	{
		thread_args[i].start_y = i * WIN_HEIGHT / N_THREADS;
		thread_args[i].end_y = (i + 1) * WIN_HEIGHT / N_THREADS;
		thread_args[i].data = data;
		if (pthread_create(&thread_ids[i], NULL, &render_fractal,
				&thread_args[i]) != 0)
			(void)(write(2, "Erorr creating thread\n", 23) + quit(4, data));
	}
	i = 0;
	while (i < N_THREADS)
		pthread_join(thread_ids[i++], NULL);
	mlx_put_image_to_window(data->win_data->mlx, data->win_data->win,
		data->win_data->img, 0, 0);
}
