/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:42:35 by troberts          #+#    #+#             */
/*   Updated: 2022/12/05 22:42:38 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalize_z(t_map_data map)
{
	int				x;
	int				y;
	t_map_point		*point;

	y = 0;
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			point = return_ptr_point(x, y, map);
			point->z = Z_RESOLUTION * (point->z - map.z.min) / (map.z.max - map.z.min);
			x++;
		}
		y++;
	}
}

void	normalize_x(t_map_data map)
{
	int				x;
	int				y;
	t_map_point		*point;

	y = 0;
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			point = return_ptr_point(x, y, map);
			point->x = Z_RESOLUTION * (point->x - map.x.min) / (map.x.max - map.x.min);
			x++;
		}
		y++;
	}
}

void	normalize_y(t_map_data map)
{
	int				x;
	int				y;
	t_map_point		*point;

	y = 0;
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			point = return_ptr_point(x, y, map);
			point->y = Z_RESOLUTION * (point->y - map.y.min) / (map.y.max - map.y.min);
			x++;
		}
		y++;
	}
}

void	normalize(t_map_data map, t_bool convert_3d)
{
	normalize_x(map, convert_3d);
	normalize_y(map, convert_3d);
	normalize_z(map);
}

void	convert_min_max_3d(t_map_data *map)
{
	t_map_point	point;

	point.x = map->x.max;
	point.y = map->y.max;
	point.z = map->z.max;
	point = convert_point(point, *map);
	map->x.max = point.x;
	map->y.max = point.y;
	map->z.max = point.z;
	point.x = map->x.min;
	point.y = map->y.min;
	point.z = map->z.min;
	point = convert_point(point, *map);
	map->x.min = point.x;
	map->y.min = point.y;
	map->z.min = point.z;
}

t_map_point	normalize_point(t_map_point point, t_map_data map)
{
	if (map.z.min != map.z.max)
		point.z = Z_RESOLUTION * (point.z - map.z.min) / (map.z.max - \
																	map.z.min);
	if (map.x.min != map.x.max)
		point.x = WIN_W * (point.x - map.x.min) / (map.x.max - map.x.min);
	if (map.y.min != map.y.max)
		point.y = WIN_H * (point.y - map.y.min) / (map.y.max - map.y.min);
	return (point);
}
