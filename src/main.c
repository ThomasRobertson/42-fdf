/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:34:36 by troberts          #+#    #+#             */
/*   Updated: 2022/12/17 22:20:36 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx			mlx;
	t_img			img;
	t_map_data		map;
	t_hook_bundle	hook_bundle;

	(void)ac;
	if (!parse_map(av[1], &map))
		return (EXIT_FAILURE);
	if (!init_window(&mlx))
		return (error_init_windows(map));
	if (!ft_mlx_new_image(mlx, &img))
		return (error_new_image(mlx, map));
	hook_bundle.img = &img;
	hook_bundle.map = &map;
	hook_bundle.mlx = &mlx;
	first_render(&map, img, mlx);
	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, \
																&hook_bundle);
	mlx_do_key_autorepeatoff(mlx.mlx_ptr);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_image(mlx.mlx_ptr, img.img_ptr);
	clean_map(&map);
	return (clean_display(mlx, EXIT_SUCCESS));
}
