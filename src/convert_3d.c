/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:59:32 by troberts          #+#    #+#             */
/*   Updated: 2023/01/05 00:39:20 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	convert_iso_point(t_map_point point, t_map_data map)
{
	double	previous_x;
	double	previous_y;

	previous_x = point.x;
	previous_y = point.y;
	point.x = (previous_x - previous_y) * cos(convert_to_rad(map.angle));
	point.y = (previous_x + previous_y) * sin(convert_to_rad(map.angle)) \
																	- point.z;
	return (point);
}

t_map_point	convert_para_point(t_map_point point, t_map_data map)
{
	double	previous_x;
	double	previous_y;

	(void)map;
	previous_x = point.x;
	previous_y = point.y;
	point.x = previous_x - point.z * cos(convert_to_rad(45));
	point.y = previous_y - point.z + sin(convert_to_rad(45));
	return (point);
}

t_map_point	convert_para2_point(t_map_point point, t_map_data map)
{
	double	previous_x;
	double	previous_y;

	(void)map;
	previous_x = point.x;
	previous_y = point.y;
	point.x = previous_y + cos(convert_to_rad(60)) * previous_x;
	point.y = -point.z + sin(convert_to_rad(60)) * previous_x;
	return (point);
}

t_map_point	convert_point(t_map_point point, t_map_data map)
{
	if (map.proj == none)
		return (point);
	if (map.proj == iso)
		return (convert_iso_point(point, map));
	else if (map.proj == para)
		return (convert_para_point(point, map));
	else if (map.proj == para2)
		return (convert_para2_point(point, map));
	else
		return (convert_iso_point(point, map));
}
