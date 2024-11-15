/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:07:53 by mdella-r          #+#    #+#             */
/*   Updated: 2024/05/31 11:37:42 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_window(t_wdata *win_data, t_gdata *data)
{
	win_data->mlx = mlx_init();
	win_data->win = mlx_new_window(win_data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Fractol");
	win_data->img = mlx_new_image(win_data->mlx, WIN_WIDTH, WIN_HEIGHT);
	win_data->addr = mlx_get_data_addr(win_data->img, &win_data->bits_per_pixel,
			&win_data->line_length, &win_data->endian);
	if (!win_data->win)
		(void)(write(2, "Error: window initialization failed\n", 36)
			+ quit(2, data));
}

static void	init_data(t_gdata *data, t_wdata *win_data)
{
	data->center.r = 0;
	data->center.i = 0;
	data->previous_center.r = -0.75;
	data->previous_center.i = 0;
	data->previous_range = STARTING_ROI_MAND;
	data->previous_max_iter = STARTING_MAX_ITER;
	data->julia_c.r = JULIA_C_R;
	data->julia_c.i = JULIA_C_I;
	data->max_iter = STARTING_MAX_ITER;
	data->win_data = win_data;
	data->color_grad = 6.3;
	if (WIN_WIDTH > WIN_HEIGHT)
		data->roi_range = STARTING_ROI_MAND * WIN_WIDTH / WIN_HEIGHT;
	else
		data->roi_range = STARTING_ROI_MAND * WIN_HEIGHT / WIN_WIDTH;
}

static void	get_const(char **argv, t_gdata *data)
{
	int	i;

	i = 0;
	while (argv[2][i] != '\0')
	{
		if ((argv[2][i] < '0' || argv[2][i] > '9'))
			if (argv[2][i] != '.' && argv[2][i] != '-' && argv[2][i] != '+')
				(void)(write(2, "Error: constant not valid\n", 27)
					+ quit(2, NULL));
		i++;
	}
	data->julia_c.r = atod(argv[2]);
	i = 0;
	if (argv[3] != NULL)
	{
		while (argv[3][i] != '\0')
		{
			if (argv[3][i] < '0' || argv[3][i] > '9')
				if (argv[3][i] != '.' && argv[3][i] != '-' && argv[3][i] != '+')
					(void)(write(2, "Error: constant not valid\n", 27)
						+ quit(2, NULL));
			i++;
		}
		data->julia_c.i = atod(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_wdata			win_data;
	t_gdata			data;

	if (argc < 2 || argc > 4)
		(void)(write(2, "Error: wrong arguments\n", 24) + quit(1, NULL));
	init_data(&data, &win_data);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data.f = &apply_mandelbrot;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		data.f = &apply_julia;
		if (argc == 3 || argc == 4)
			get_const(argv, &data);
	}
	else if (ft_strcmp(argv[1], "ship") == 0)
		data.f = &apply_ship;
	else
		(void)(write(2, "Error: ", 8) + write(1, ERROR_ARG, 31)
			+ quit(3, NULL));
	init_window(&win_data, &data);
	call_threads(&data);
	mlx_mouse_hook(win_data.win, &mouse_hook, &data);
	mlx_hook(win_data.win, 2, 1, &key_hook, &data);
	mlx_hook(win_data.win, 17, 1L << 17, &press_x, &data);
	mlx_loop(win_data.mlx);
}
