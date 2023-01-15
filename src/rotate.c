/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:45:27 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 05:15:26 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	rotate_point(t_map_point point, t_map_data map)
{
	t_map_point	no_rotation;

	no_rotation = convert_point(point, map);
	point.y_no_rotation = no_rotation.y;
	if (map.proj == none)
		return (point);
	point = rotate_x(point, map);
	point = rotate_y(point, map);
	point = rotate_z(point, map);
	return (point);
}

t_map_point	rotate_x(t_map_point point, t_map_data map)
{
	t_map_point	previous;

	previous = point;
	point.y = previous.y * cos(map.rotate_value.x) + \
								point.z * sin(map.rotate_value.x);
	point.z = -previous.y * sin(map.rotate_value.x) + \
								point.z * cos(map.rotate_value.x);
	return (point);
}

t_map_point	rotate_y(t_map_point point, t_map_data map)
{
	t_map_point	previous;

	previous = point;
	point.x = previous.x * cos(map.rotate_value.y) + \
								point.z * sin(map.rotate_value.y);
	point.z = -previous.x * sin(map.rotate_value.y) + \
								point.z * cos(map.rotate_value.y);
	return (point);
}

t_map_point	rotate_z(t_map_point point, t_map_data map)
{
	t_map_point	previous;

	previous = point;
	point.x = previous.x * cos(map.rotate_value.z) - \
								previous.y * sin(map.rotate_value.z);
	point.y = previous.x * sin(map.rotate_value.z) + \
								previous.y * cos(map.rotate_value.z);
	return (point);
}
