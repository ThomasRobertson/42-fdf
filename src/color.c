/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:04:53 by troberts          #+#    #+#             */
/*   Updated: 2022/12/05 23:44:11 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_background(t_img img)
{
	t_map_point	start;
	t_map_point	end;
	int			y;

	y = 0;
	start.x = 0;
	end.x = WIN_W - 1;
	start.color = DEFAULT_COLOR_BG;
	end.color = DEFAULT_COLOR_BG;
	while (y < WIN_H)
	{
		start.y = y;
		end.y = y;
		bresenham(img, start, end);
		y++;
	}
}

// int	get_ration(int distance, int distance_min, int distance_max)
// {
// 	if (distance_max == distance_min)
// 		return (100);
// 	return (((distance - distance_min) * 100) / ((distance_max - distance_min)
// 			* 100))
// }

// t_color	add_shade(int ratio, t_color color, int argb_target)
// {
// 	// wip
// }
