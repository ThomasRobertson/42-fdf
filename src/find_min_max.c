/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:37:26 by troberts          #+#    #+#             */
/*   Updated: 2022/11/27 21:55:45 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_max_min_z(t_map_data map, int *min, int *max)
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
			if (point->z > *max)
				*max = point->z;
			if (point->z < *min)
				*min = point->z;
			x++;
		}
		y++;
	}
}

void	find_max_min_x(t_map_data map, double *min, double *max, \
														t_bool convert_3d)
{
	int				x;
	int				y;
	t_map_point		point;

	y = 0;
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			point = return_point(x, y, map);
			if (convert_3d == true)
				point = convert_point(point, map);
			if (point.x > *max)
				*max = point.x;
			if (point.x < *min)
				*min = point.x;
			x++;
		}
		y++;
	}
}

void	find_max_min_y(t_map_data map, double *min, double *max, \
														t_bool convert_3d)
{
	int				x;
	int				y;
	t_map_point		point;

	y = 0;
	while (y < map.nbr_row)
	{
		x = 0;
		while (x < map.nbr_line)
		{
			point = return_point(x, y, map);
			if (convert_3d == true)
				point = convert_point(point, map);
			if (point.y > *max)
				*max = point.y;
			if (point.y < *min)
				*min = point.y;
			x++;
		}
		y++;
	}
}