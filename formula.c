/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:30:21 by mdella-r          #+#    #+#             */
/*   Updated: 2023/12/20 13:29:26 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_dcoord	apply_mandelbrot(t_dcoord old, t_dcoord c, t_gdata *data)
{
	t_dcoord	new;

	(void)data;
	new.r = old.r * old.r - old.i * old.i + c.r;
	new.i = 2 * old.r * old.i + c.i;
	return (new);
}

t_dcoord	apply_julia(t_dcoord old, t_dcoord c, t_gdata *data)
{
	t_dcoord	new;

	if (old.r == 0 && old.i == 0)
	{
		old.r = c.r;
		old.i = c.i;
	}
	c.r = data->julia_c.r;
	c.i = data->julia_c.i;
	new.r = old.r * old.r - old.i * old.i + c.r;
	new.i = 2 * old.r * old.i + c.i;
	return (new);
}

t_dcoord	apply_ship(t_dcoord old, t_dcoord c, t_gdata *data)
{
	t_dcoord	new;

	(void)data;
	new.r = old.r * old.r - old.i * old.i + c.r;
	new.i = 2 * old.r * old.i + c.i;
	if (new.r < 0)
		new.r = -new.r;
	if (new.i < 0)
		new.i = -new.i;
	return (new);
}
