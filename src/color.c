/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:04:53 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 16:53:41 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_background(t_img img, int max_x, int max_y, unsigned int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			ft_mlx_pixel_put(&img, x, y, color);
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

	if (!USE_COLOR)
		return (DEFAULT_COLOR);
	if ((int)start.color == (int)end.color)
		return (start.color);
	if (fabs(end.y - start.y) >= fabs(end.x - start.x))
		percent = (point.y - start.y) / ((int)end.y - (int)start.y);
	else
		percent = (point.x - start.x) / ((int)end.x - (int)start.x);
	color.a = TRANSPARENCY;
	color.r = (1 - percent) * get_r(start.color) + percent * get_r(end.color);
	color.g = (1 - percent) * get_g(start.color) + percent * get_g(end.color);
	color.b = (1 - percent) * get_b(start.color) + percent * get_b(end.color);
	if (convert_to_argb(color) == (int)0xffE9E700)
		(void)end;
	return (convert_to_argb(color));
}
