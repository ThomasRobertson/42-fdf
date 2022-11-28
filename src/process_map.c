/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:21:31 by troberts          #+#    #+#             */
/*   Updated: 2022/11/26 23:05:33 by troberts         ###   ########.fr       */
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
