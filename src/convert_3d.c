/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:59:32 by troberts          #+#    #+#             */
/*   Updated: 2023/01/10 23:37:25 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	convert_iso_point(t_map_point point)
{
	t_map_point	old;

	old = point;
	point.x = (old.x - old.y) * cos(convert_to_rad(30));
	point.y = (old.x + old.y) * sin(convert_to_rad(30)) - point.z;
	return (point);
}

t_map_point	convert_para_point(t_map_point point)
{
	t_map_point	old;

	old = point;
	point.x = old.x - point.z * cos(convert_to_rad(45));
	point.y = old.y - point.z + sin(convert_to_rad(45));
	return (point);
}

t_map_point	convert_para2_point(t_map_point point)
{
	t_map_point	old;

	old = point;
	point.x = old.y + cos(convert_to_rad(60)) * old.x;
	point.y = -point.z + sin(convert_to_rad(60)) * old.x;
	return (point);
}

t_map_point	convert_point(t_map_point point, t_map_data map)
{
	if (map.proj == none)
		return (point);
	if (map.proj == iso)
		return (convert_iso_point(point));
	else if (map.proj == para)
		return (convert_para_point(point));
	else if (map.proj == para2)
		return (convert_para2_point(point));
	else
		return (convert_iso_point(point));
}
