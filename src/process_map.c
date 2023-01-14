/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:21:31 by troberts          #+#    #+#             */
/*   Updated: 2023/01/14 02:20:16 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	offset_point(t_map_point point, t_map_data map)
{
	(void)map;
	point.x = (WIN_W * (map.margin.left + MENU_W)) + ((double)point.x / \
		((double)WIN_W) * (WIN_W - (WIN_W * \
			(map.margin.right + map.margin.left + MENU_W))));
	point.y = (WIN_H * map.margin.top) + ((double)point.y / \
		((double)WIN_H) * (WIN_H - (WIN_H * \
			(map.margin.bottom + map.margin.top))));
	return (point);
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
