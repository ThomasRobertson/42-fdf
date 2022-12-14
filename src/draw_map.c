/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:54:10 by troberts          #+#    #+#             */
/*   Updated: 2022/12/14 17:00:03 by troberts         ###   ########.fr       */
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
		while (x + 1 < map.nbr_line)
		{
			end = get_start_end_point_x(map, &start, x, y);
			drawline(img, &start, &end);
			end = get_start_end_point_y(map, &start, x, y);
			drawline(img, &start, &end);
			x++;
		}
		y++;
		end = get_start_end_point_y(map, &start, x, y);
		drawline(img, &start, &end);
	}
}

void	process_start_and_point(t_map_data map, t_map_point *start, \
															t_map_point *end)
{
	*start = convert_iso_point(*start, map);
	*start = normalize_point(*start, map);
	*start = offset_point(*start, map);
	*end = convert_iso_point(*end, map);
	*end = normalize_point(*end, map);
	*end = offset_point(*end, map);
}

t_map_point	get_start_end_point_y(t_map_data map, t_map_point *start, \
									int x, int y)
{
	t_map_point	end;

	*start = return_point(x, y, map);
	end = return_point(x, y + 1, map);
	process_start_and_point(map, start, &end);
	return (end);
}

t_map_point	get_start_end_point_x(t_map_data map, t_map_point *start, \
									int x, int y)
{
	t_map_point	end;

	*start = return_point(x, y, map);
	end = return_point(x + 1, y, map);
	process_start_and_point(map, start, &end);
	return (end);
}