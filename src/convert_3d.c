/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:59:32 by troberts          #+#    #+#             */
/*   Updated: 2022/11/27 21:54:24 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	convert_point(t_map_point point, t_map_data map)
{
	if (map.proj == iso)
		return (convert_iso_point(point, map));
	else
		return (convert_iso_point(point, map));
}

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
