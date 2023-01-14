/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:02:42 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 00:31:10 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_hook(t_mlx mlx, t_hook_bundle *hook)
{
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, \
																hook);
	mlx_hook(mlx.win_ptr, DestroyNotify, StructureNotifyMask, &handle_close, \
																hook);
}

void	set_up_look_and_hook(t_mlx *mlx, t_img *img, t_map_data *map, \
														t_hook_bundle *hook)
{
	hook->img = img;
	hook->map = map;
	hook->mlx = mlx;
	mlx_loop_hook(mlx->mlx_ptr, &handle_no_event, &mlx);
	add_hook(*mlx, hook);
	mlx_loop(mlx->mlx_ptr);
}
