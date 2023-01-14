/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:34:36 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 00:28:47 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx			mlx;
	t_img			img;
	t_map_data		map;
	t_hook_bundle	hook_bundle;

	if (ac != 2)
		return (error_args());
	if (!parse_map(av[1], &map))
		return (EXIT_FAILURE);
	if (!init_window(&mlx))
		return (error_init_windows(map));
	if (!ft_mlx_new_image(mlx, &img))
		return (error_new_image(mlx, map));
	first_render(&map, img, &mlx);
	set_up_look_and_hook(&mlx, &img, &map, &hook_bundle);
	return (clean_exit(mlx, img, &map));
}
