/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:14 by troberts          #+#    #+#             */
/*   Updated: 2022/12/06 21:29:27 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_render(t_map_data *map, t_img img, t_mlx mlx)
{
	map->angle = ANGLE;
	map->proj = DEFAULT_PROJ;
	map->overwrite_color = true;
	find_max_min(map);
	fill_background(img);
	draw_3d(*map, img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
}

void	render(t_map_data map, t_img img, t_mlx mlx)
{
	fill_background(img);
	draw_3d(map, img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
}
