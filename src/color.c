/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:04:53 by troberts          #+#    #+#             */
/*   Updated: 2022/12/08 12:46:23 by troberts         ###   ########.fr       */
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

unsigned int	get_valid_color(char *strchr_ptr)
{
	t_color			color;
	unsigned int	color_to_convert;

	color_to_convert = (unsigned int)ft_atoi_base(strchr_ptr + 3, "0123456789ABCDEF");
	color.a = TRANSPARENCY;
	color.r = get_r(color_to_convert);
	color.g = get_g(color_to_convert);
	color.b = get_b(color_to_convert);
	return (convert_to_argb(color));
}

// unsigned int	get_percent(t_map_point point, t_map_data map)
// {
// 	return (100 * point.z / map.y.max);
// }

unsigned int	get_color_gradient(t_map_point start, t_map_point end, \
											t_map_point point, t_map_data map)
{
	t_color	color;
	double	percent;

	if (start.color == end.color)
		return (start.color);
	percent = point.z / map.y.max;
	color.a = 255;
	// ((int)((1 - percentage) * start + percentage * end))
	color.r = (1 - percent) * get_r(start.color) + percent * get_r(end.color);
	color.g = (1 - percent) * get_g(start.color) + percent * get_g(end.color);
	color.b = (1 - percent) * get_b(start.color) + percent * get_b(end.color);
	// color.r = get_percent(point, map) * get_r(start.color) + (get_percent(point, map) - 1) * get_r(end.color);
	// color.g = get_percent(point, map) * get_g(start.color) + (get_percent(point, map) - 1) * get_g(end.color);
	// color.b = get_percent(point, map) * get_b(start.color) + (get_percent(point, map) - 1) * get_b(end.color);
	return (convert_to_argb(color));
}
