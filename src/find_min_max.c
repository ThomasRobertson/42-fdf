/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:37:26 by troberts          #+#    #+#             */
/*   Updated: 2023/01/13 23:34:56 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_max_min_z(t_map_data *map)
{
	double			x;
	double			y;
	t_map_point		point;

	y = 0;
	while (y < map->nbr_row)
	{
		x = 0;
		while (x < map->nbr_line)
		{
			point = return_point(x, y, *map);
			if (point.z > map->z.max)
				map->z.max = point.z;
			if (point.z < map->z.min)
				map->z.min = point.z;
			x++;
		}
		y++;
	}
}

void	find_max_min_x(t_map_data *map)
{
	double			x;
	double			y;
	t_map_point		point;

	y = 0;
	while (y < map->nbr_row)
	{
		x = 0;
		while (x < map->nbr_line)
		{
			point = return_point(x, y, *map);
			point = convert_point(point, *map);
			if (point.x > map->x.max)
				map->x.max = point.x;
			if (point.x < map->x.min)
				map->x.min = point.x;
			x++;
		}
		y++;
	}
}

void	find_max_min_y(t_map_data *map)
{
	double			x;
	double			y;
	t_map_point		point;

	y = 0;
	while (y < map->nbr_row)
	{
		x = 0;
		while (x < map->nbr_line)
		{
			point = return_point(x, y, *map);
			point = convert_point(point, *map);
			if (point.y > map->y.max)
				map->y.max = point.y;
			if (point.y < map->y.min)
				map->y.min = point.y;
			x++;
		}
		y++;
	}
}

void	find_max_min(t_map_data *map)
{
	map->x.min = DBL_MAX;
	map->x.max = DBL_MIN;
	map->y.min = DBL_MAX;
	map->y.max = DBL_MIN;
	map->z.min = DBL_MAX;
	map->z.max = DBL_MIN;
	find_max_min_x(map);
	find_max_min_y(map);
	find_max_min_z(map);
}
