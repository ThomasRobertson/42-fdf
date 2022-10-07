/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:40:16 by troberts          #+#    #+#             */
/*   Updated: 2022/10/07 16:05:08 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	fill_t_line(int x1, int y1, int x2, int y2)
{
	t_line	line;

	line.x1 = x1;
	line.y1 = y1;
	line.x2 = x2;
	line.y2 = y2;
	line.color = DEFAULT_COLOR;
	return (line);
}

void	drawline(t_img img, t_line line)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	error_bound;

	x = line.x1;
	y = line.y1;
	delta_x = line.x2 - line.x1;
	delta_y = line.y2 - line.y1;
	error_bound = delta_y - delta_x;
	while (x <= line.x2)
	{
		ft_mlx_pixel_put(&img, x, y, line.color);
		if (error_bound >= 0)
		{
			y++;
			error_bound = error_bound - delta_x;
		}
		else
		{
			error_bound = error_bound + delta_y;
			x++;
		}
	}
}