/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:04:53 by troberts          #+#    #+#             */
/*   Updated: 2022/12/06 23:20:42 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_background(t_img img)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ft_mlx_pixel_put(&img, x, y, DEFAULT_COLOR_BG);
			x++;
		}
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
