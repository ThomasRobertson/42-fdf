/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:34:36 by troberts          #+#    #+#             */
/*   Updated: 2022/10/07 16:15:01 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_mlx	mlx;
	t_img	img;
	t_line	line;

	if (init_window(&mlx))
		return (EXIT_FAILURE);
	if (ft_mlx_new_image(mlx, &img))
		return (clean_window_display(mlx, EXIT_FAILURE));
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
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_image(mlx.mlx_ptr, img.img_ptr);
	return (clean_display(mlx, EXIT_SUCCESS));
}
