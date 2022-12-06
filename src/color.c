/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:04:53 by troberts          #+#    #+#             */
/*   Updated: 2022/12/06 23:23:28 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_background(t_img img)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ft_mlx_pixel_put(&img, x, y, DEFAULT_COLOR_BG);
			x++;
		}
		y++;
	}
}

unsigned int	get_percent(t_map_point point, t_map_data map)
{
	return (100 * point.z / map.y.max);
}

unsigned int	get_color_gradient(t_map_point start, t_map_point end, \
															t_map_point point)
{
	t_color	color;

	color.a = 255;
	color.r = point.z * get_r(start.color) + (point.z - 1) * get_r(end.color);
	color.g = point.z * get_g(start.color) + (point.z - 1) * get_g(end.color);
	color.b = point.z * get_b(start.color) + (point.z - 1) * get_b(end.color);
	return (convert_to_argb(color));
}
