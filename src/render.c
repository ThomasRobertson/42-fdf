/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:14 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 19:11:56 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_render(t_map_data *map, t_img img, t_mlx *mlx)
{
	map->proj = DEFAULT_PROJ;
	map->margin.bottom = BOTTOM_MARGIN;
	map->margin.top = TOP_MARGIN;
	map->margin.right = RIGHT_MARGIN;
	map->margin.left = LEFT_MARGIN;
	map->rotate_value.x = DEFAULT_ROTATE;
	map->rotate_value.y = DEFAULT_ROTATE;
	map->rotate_value.z = DEFAULT_ROTATE;
	find_max_min(map);
	mlx_do_sync(mlx->mlx_ptr);
	fill_background(img, WIN_W, WIN_H, DEFAULT_COLOR_BG);
	draw_map(*map, img);
	mlx_do_key_autorepeaton(mlx->mlx_ptr);
	fill_background(img, WIN_W * (double)MENU_W, WIN_H, DEFAULT_COLOR_MENU);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	draw_menu(*mlx);
}

void	render(t_map_data map, t_img img, t_mlx mlx)
{
	mlx_do_sync(mlx.mlx_ptr);
	fill_background(img, WIN_W, WIN_H, DEFAULT_COLOR_BG);
	draw_map(map, img);
	fill_background(img, WIN_W * (double)MENU_W, WIN_H, DEFAULT_COLOR_MENU);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	draw_menu(mlx);
}
