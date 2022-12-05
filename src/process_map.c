/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:21:31 by troberts          #+#    #+#             */
/*   Updated: 2022/12/05 22:48:42 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	offset_point(t_map_point point, t_map_data map)
{
	(void)map;
	point.x = (WIN_W * LEFT_MARGIN) + ((double)point.x / \
		((double)WIN_W) * (WIN_W - (WIN_W * \
			(RIGHT_MARGIN + LEFT_MARGIN))));
	point.y = (WIN_H * TOP_MARGIN) + ((double)point.y / \
		((double)WIN_H) * (WIN_H - (WIN_H * \
			(BOTTOM_MARGIN + TOP_MARGIN))));
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
