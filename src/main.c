/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:34:36 by troberts          #+#    #+#             */
/*   Updated: 2022/12/05 23:44:52 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_img		img;
	t_map_data	map;

	(void)ac;
	if (!parse_map(av[1], &map))
		return (EXIT_FAILURE);
	if (!init_window(&mlx))
		return (error_init_windows(map));
	if (!ft_mlx_new_image(mlx, &img))
		return (error_new_image(mlx, map));
	fill_background(img);
	// draw_3d(map, img);
 	// unsigned int x = 0;
	// unsigned int y = 0;
	// t_map_point *point;
	// while (return_ptr_point(1, y, map))
	// {
	// 	point = return_ptr_point(x, y, map);
	// 	while (point)
	// 	{
	// 		int x2 = point->x;
	// 		int y2 = point->y;
	// 		int z2 = point->z;
	// 		printf("x: %i y: %i z: %i\n", x2, y2, z2);
	// 		x++;
	// 		point = return_ptr_point(x, y, map);
	// 	}
	// 	y++;
	// }
	// x = 0;
	// y = 0;
	// // normalize_z(map);
	// // offset_coord(map);
	// while (return_ptr_point(1, y, map))
	// {
	// 	point = return_ptr_point(x, y, map);
	// 	while (point)
	// 	{
	// 		int x2 = point->x;
	// 		int y2 = point->y;
	// 		int z2 = point->z;
	// 		printf("x: %i y: %i z: %i\n", x2, y2, z2);
	// 		x++;
	// 		point = return_ptr_point(x, y, map);
	// 	}
	// 	y++;
	// }
	draw_3d(map, img);
	// t_map_point a;
	// t_map_point b;
	// b.x = 0;
	// b.y = 0;
	// b.color = 0x00FF0000;
	// a.x = 800;
	// a.y = 800;
	// a.color = 0x00FF0000;
	// drawline(img, &a, &b);
	// a.x = 800;
	// a.y = 0;
	// b.x = 0;
	// b.y = 801;
	// drawline(img, &a, &b);
	// a.x = 300;
	// a.y = 0;
	// b.x = 300;
	// b.y = 801;
	// drawline(img, &a, &b);
	// a.x = 0;
	// a.y = 300;
	// b.x = 801;
	// b.y = 300;
	// drawline(img, &a, &b);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &mlx);
	mlx_hook(mlx.win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_image(mlx.mlx_ptr, img.img_ptr);
	clean_map(&map);
	return (clean_display(mlx, EXIT_SUCCESS));
}
