/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:04:46 by mdella-r          #+#    #+#             */
/*   Updated: 2023/12/20 14:16:36 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	quit(char id, t_gdata *data)
{
	t_wdata	*win_data;

	if (data)
	{
		win_data = data->win_data;
		mlx_destroy_window(win_data->mlx, win_data->win);
		mlx_destroy_image(win_data->mlx, win_data->img);
		mlx_destroy_display(win_data->mlx);
		free(win_data->mlx);
	}
	exit(id);
}

int	press_x(t_gdata *data)
{
	quit(0, data);
	return (0);
}

double	atod(char *argv)
{
	double			r;
	double			n;
	unsigned short	i;
	unsigned short	j;

	r = 0;
	n = 0;
	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i] && argv[i] != '.')
		r = r * 10 + (argv[i++] - 48);
	j = i + 1;
	if (argv[i] == '.')
		while (argv[++i])
			n = n * 10 + (argv[i] - 48);
	r += n / pow(10, ft_strlen(argv + j));
	if (argv[0] == '-')
		return (r * -1);
	return (r);
}
