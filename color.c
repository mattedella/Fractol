/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:24:05 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/11 11:58:25 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_gdata *data, int x, int y, unsigned short intensity)
{
	int		index;
	t_rgb	color;
	double	grad;

	if (data->color_grad > 7.0)
		data->color_grad = 6.0;
	grad = (double)intensity / data->max_iter;
	color.r = sin(data->color_grad * intensity + 0) * 127 + 128;
	color.g = sin(data->color_grad * intensity + 4 * PI / 3) * 127 + 128;
	color.b = cos(data->color_grad * intensity + 2 * PI / 3) * 127 + 128;
	color.r *= grad * 100;
	color.g *= grad * 100;
	color.b *= grad * 100;
	index = y * data->win_data->line_length + x
		* (data->win_data->bits_per_pixel / 8);
	data->win_data->addr[index] = (unsigned char)color.b;
	data->win_data->addr[index + 1] = (unsigned char)color.g;
	data->win_data->addr[index + 2] = (unsigned char)color.r;
	if (intensity == (int)data->max_iter)
	{
		data->win_data->addr[index] = 0;
		data->win_data->addr[index + 1] = 0;
		data->win_data->addr[index + 2] = 0;
	}
}
