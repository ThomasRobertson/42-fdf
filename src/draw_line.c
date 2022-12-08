/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:40:16 by troberts          #+#    #+#             */
/*   Updated: 2022/12/08 00:01:40 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(t_img img, t_map_point const *start, t_map_point const *end, t_map_data map)
{
	bresenham(img, *start, *end, map);
}

void	bresenham(t_img img, t_map_point start, t_map_point end, t_map_data map)
{
	int dx = abs((int)end.x - (int)start.x);
	int sx = (int)start.x < (int)end.x ? 1 : -1;
	int dy = -abs((int)end.y - (int)start.y);
	int sy = (int)start.y < (int)end.y ? 1 : -1;
	int error = dx + dy;
	t_map_point	point;

	point = start;
	while (true)
	{
		ft_mlx_pixel_put(&img, (int)point.x, (int)point.y, get_color_gradient(start, end, point, map));
		if ((int)point.x == (int)end.x && (int)point.y == (int)end.y)
			break ;
		if ((error * 2) >= dy)
		{
			if ((int)point.x == (int)end.x)
				break ;
			error = error + dy;
			point.x = (int)point.x + sx;
		}
		if ((error * 2) <= dx)
		{
			if ((int)point.y == (int)end.y)
				break ;
			error = error + dx;
			point.y = (int)point.y + sy;
		}
	}
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;
	int		i;

	if (x > WIN_W - 1 || x < 0)
		return ;
	if (y > WIN_H - 1 || y < 0)
		return ;
	i = img->bits_per_pixel - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}
