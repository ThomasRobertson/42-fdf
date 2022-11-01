/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:34:36 by troberts          #+#    #+#             */
/*   Updated: 2022/11/01 15:24:45 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_img		img;
	t_draw_line	line;
	t_map_data	map;

	(void)ac;
	if (!parse_map(av[1], &map))
		return (EXIT_FAILURE);
	if (!init_window(&mlx))
		return (EXIT_FAILURE);
	if (!ft_mlx_new_image(mlx, &img))
		return (clean_window_display(mlx, EXIT_FAILURE));
	unsigned int x = 0;
	unsigned int y = 0;
	t_map_point *point;
	while (return_ptr_point(1, y, map))
	{
		point = return_ptr_point(x, y, map);
		while (point)
		{
			int x2 = point->x;
			int y2 = point->y;
			int z2 = point->z;
			printf("x: %i y: %i z: %i\n", x2, y2, z2);
			x++;
			point = return_ptr_point(x, y, map);
		}
		y++;
	}
	line.x1 = 20;
	line.y1 = 20;
	line.x2 = 500;
	line.y2 = 800;
	line.color = 0xFF00FF00;
	ft_mlx_pixel_put(&img, 500, WIN_H, 0xFF00FF00);
	drawline(img, line);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &mlx);
	mlx_hook(mlx.win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, &mlx);
	//mlx_loop(mlx.mlx_ptr);
	mlx_destroy_image(mlx.mlx_ptr, img.img_ptr);
	return (clean_display(mlx, EXIT_SUCCESS));
}
