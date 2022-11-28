/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:40:16 by troberts          #+#    #+#             */
/*   Updated: 2022/11/27 22:02:32 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(t_img img, t_map_point const *start, t_map_point const *end)
{
	//printf("x: %i, y: %i - ", (int)start->x, (int)start->y); // DO REMOVE
	//printf("x: %i, y: %i\n", (int)end->x, (int)end->y); // DO REMOVE
	// if (start == NULL || end == NULL)
	// 	return ;
	// if (start->x == end->x && start->y == end->y)
	// 	ft_mlx_pixel_put(&img, start->x, start->y, start->color);
	// else if (start->x == end->x || start->y == end->y)
	// 	straight_line(img, *start, *end);
	// else
	bresenham(img, *start, *end);
}

void	straight_line(t_img img, t_map_point start, t_map_point end)
{
	if ((int)start.x == (int)end.x)
	{
		if ((int)start.y > (int)end.y)
			swap(&start, &end);
		while ((int)start.y <= (int)end.y)
		{
			ft_mlx_pixel_put(&img, (int)start.x, (int)start.y, start.color);
			start.y++;
		}
	}
	else
	{
		if ((int)start.x > (int)end.x)
			swap(&start, &end);
		while ((int)start.x <= (int)end.x)
		{
			ft_mlx_pixel_put(&img, (int)start.x, (int)start.y, start.color);
			start.x++;
		}
	}
}

void	bresenham(t_img img, t_map_point start, t_map_point end)
{
	int dx = abs((int)end.x - (int)start.x);
	int sx = (int)start.x < (int)end.x ? 1 : -1;
	int dy = -abs((int)end.y - (int)start.y);
	int sy = (int)start.y < (int)end.y ? 1 : -1;
	int error = dx + dy;

	while (true)
	{
		ft_mlx_pixel_put(&img, (int)start.x, (int)start.y, (int)start.color);
		if ((int)start.x == (int)end.x && (int)start.y == (int)end.y)
			break ;
		if ((error * 2) >= dy)
		{
			if ((int)start.x == (int)end.x)
				break ;
			error = error + dy;
			start.x = (int)start.x + sx;
		}
		if ((error * 2) <= dx)
		{
			if ((int)start.y == (int)end.y)
				break ;
			error = error + dx;
			start.y = (int)start.y + sy;
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
