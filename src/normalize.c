/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:42:35 by troberts          #+#    #+#             */
/*   Updated: 2022/11/27 21:56:05 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalize_z(t_map_data map)
{
	int				min;
	int				max;
	int				x;
	int				y;
	t_map_point		*point;

	max = INT_MIN;
	min = INT_MAX;
	y = 0;
	find_max_min_z(map, &min, &max);
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			point = return_ptr_point(x, y, map);
			point->z = Z_RESOLUTION * (point->z - min) / (max - min);
			x++;
		}
		y++;
	}
}

void	normalize_x(t_map_data map, t_bool convert_3d)
{
	double			min;
	double			max;
	int				x;
	int				y;
	t_map_point		*point;

	max = DBL_MIN;
	min = DBL_MAX;
	y = 0;
	find_max_min_x(map, &min, &max, convert_3d);
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			point = return_ptr_point(x, y, map);
			point->x = Z_RESOLUTION * (point->x - min) / (max - min);
			x++;
		}
		y++;
	}
}

void	normalize_y(t_map_data map, t_bool convert_3d)
{
	double			min;
	double			max;
	int				x;
	int				y;
	t_map_point		*point;

	max = DBL_MIN;
	min = DBL_MAX;
	y = 0;
	find_max_min_y(map, &min, &max, convert_3d);
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			point = return_ptr_point(x, y, map);
			point->y = Z_RESOLUTION * (point->y - min) / (max - min);
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

t_map_point	normalize_point(t_map_point point, t_map_data map, \
															t_bool convert_3d)
{
	double	min;
	double	max;
	int		min_z;
	int		max_z;

	(void)map;
	max_z = INT_MIN;
	min_z = INT_MAX;
	find_max_min_z(map, &min_z, &max_z);
	if (min_z != max_z)
		point.z = Z_RESOLUTION * (point.z - min_z) / (max_z - min_z);
	max = DBL_MIN;
	min = DBL_MAX;
	find_max_min_x(map, &min, &max, convert_3d);
	if (min != max)
		point.x = WIN_W * (point.x - min) / (max - min);
	max = DBL_MIN;
	min = DBL_MAX;
	find_max_min_y(map, &min, &max, convert_3d);
	if (min != max)
		point.y = WIN_H * (point.y - min) / (max - min);
	return (point);
}
