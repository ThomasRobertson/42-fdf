/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:40:16 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 05:12:25 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	sx_sy(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}

int	bresenham_init(int *error, t_map_point *point, t_map_point start, \
															t_map_point end)
{
	if (start.y < 0 && end.y < 0)
		return (RETURN_FAILURE);
	if (start.y > WIN_H && end.y > WIN_H)
		return (RETURN_FAILURE);
	if (start.x < 0 && end.x < 0)
		return (RETURN_FAILURE);
	if (start.x > WIN_W && end.x > WIN_W)
		return (RETURN_FAILURE);
	*point = start;
	*error = abs((int)end.x - (int)start.x) + -abs((int)end.y - (int)start.y);
	return (RETURN_SUCCESS);
}

void	bresenham_for_the_norm(int *error, double *y, t_map_point start, \
																t_map_point end)
{
	*error = *error + abs((int)end.x - (int)start.x);
	*y = *y + sx_sy(start.y, end.y);
}

void	drawline(t_img img, t_map_point start, t_map_point end)
{
	int			error;
	t_map_point	point;

	if (!bresenham_init(&error, &point, start, end))
		return ;
	while (true)
	{
		ft_mlx_pixel_put(&img, (int)point.x, (int)point.y, \
									get_color_gradient(start, end, point));
		if ((int)point.x == (int)end.x && (int)point.y == (int)end.y)
			break ;
		if ((error * 2) >= -abs((int)end.y - (int)start.y))
		{
			if ((int)point.x == (int)end.x)
				break ;
			error = error + -abs((int)end.y - (int)start.y);
			point.x = point.x + sx_sy(start.x, end.x);
		}
		if ((error * 2) <= abs((int)end.x - (int)start.x))
		{
			if ((int)point.y == (int)end.y)
				break ;
			bresenham_for_the_norm(&error, &point.y, start, end);
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
