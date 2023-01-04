/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:04:53 by troberts          #+#    #+#             */
/*   Updated: 2023/01/05 00:25:43 by troberts         ###   ########.fr       */
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
	size_t			len;

	len = ft_strlen(strchr_ptr);
	string_upper(strchr_ptr);
	color_to_convert = (unsigned int)ft_atoi_base(strchr_ptr + 2, \
														"0123456789ABCDEF");
	if (len == 10)
		return (color_to_convert);
	if (len % 2 != 0)
		return (DEFAULT_COLOR);
	color.r = get_r(color_to_convert);
	color.g = get_g(color_to_convert);
	color.b = get_b(color_to_convert);
	if (len < 10)
		color.a = TRANSPARENCY;
	if (len < 8)
		color.r = 0;
	if (len < 6)
		color.g = 0;
	if (len < 4)
		color.b = 0;
	return (convert_to_argb(color));
}

unsigned int	get_color_gradient(t_map_point start, t_map_point end, \
															t_map_point point)
{
	t_color	color;
	double	percent;

	if (start.color == end.color)
		return (start.color);
	if (start.y == end.y)
		return (start.color);
	percent = (point.y - start.y) / (end.y - start.y);
	color.a = TRANSPARENCY;
	color.r = (1 - percent) * get_r(start.color) + percent * get_r(end.color);
	color.g = (1 - percent) * get_g(start.color) + percent * get_g(end.color);
	color.b = (1 - percent) * get_b(start.color) + percent * get_b(end.color);
	return (convert_to_argb(color));
}

unsigned int	get_fixed_color_gradient(int line_len, int i, t_map_point start, t_map_point end)
{
	t_color	color;
	double	percent;

	// if (start.z > end.z)
	// 	swap(&start, &end);
	if (start.z == end.z || ft_abs(end.z - start.z) == 0)
		percent = start.z / Z_RESOLUTION;
	else
	{
		percent = ((double)end.z - (double)start.z) / Z_RESOLUTION;
		percent *= (double)i / (double)line_len;
		percent += (start.z / Z_RESOLUTION);
	}
	color.a = TRANSPARENCY;
	color.r = (1 - percent) * get_r(LOW_COLOR) + percent * get_r(HIGH_COLOR);
	color.g = (1 - percent) * get_g(LOW_COLOR) + percent * get_g(HIGH_COLOR);
	color.b = (1 - percent) * get_b(LOW_COLOR) + percent * get_b(HIGH_COLOR);
	return (convert_to_argb(color));
}

// unsigned int	get_color(t_map_point start, t_map_point end, \
// 											t_map_point point, t_map_data map)
// {
// 	(void)map;
// 	(void)start;
// 	(void)end;
// 	// if (map.overwrite_color == true)
// 	// 	return (get_fixed_color_gradient(point));
// 	// else
// 	// 	return (get_color_gradient(start, end, point));
// 	return (get_fixed_color_gradient(point));
// }