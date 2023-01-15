/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:54:10 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 05:13:24 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_map_data map, t_img img)
{
	int				x;
	int				y;
	t_map_point		start;
	t_map_point		end;

	y = 0;
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			end = get_start_end_point_x(map, &start, x, y);
			drawline(img, start, end);
			end = get_start_end_point_y(map, &start, x, y);
			drawline(img, start, end);
			x++;
		}
		y++;
		end = get_start_end_point_y(map, &start, x, y);
		drawline(img, start, end);
	}
}

t_map_point	process_point(t_map_data map, t_map_point point)
{
	point = rotate_point(point, map);
	point = convert_point(point, map);
	point = normalize_point(point, map);
	point = offset_point(point, map);
	return (point);
}

t_map_point	get_start_end_point_y(t_map_data map, t_map_point *start, \
									int x, int y)
{
	t_map_point	end;

	*start = return_point(x, y, map);
	end = return_point(x, y + 1, map);
	*start = process_point(map, *start);
	end = process_point(map, end);
	return (end);
}

t_map_point	get_start_end_point_x(t_map_data map, t_map_point *start, \
									int x, int y)
{
	t_map_point	end;

	*start = return_point(x, y, map);
	end = return_point(x + 1, y, map);
	*start = process_point(map, *start);
	end = process_point(map, end);
	return (end);
}
