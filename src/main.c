/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:34:36 by troberts          #+#    #+#             */
/*   Updated: 2022/09/25 20:45:11 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_mlx	mlx;
	t_data	img;

	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1280, 720, "Hello world!");
	if (mlx.win_ptr == NULL)
		return (EXIT_FAILURE);
	img.img = mlx_new_image(mlx.mlx_ptr, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
										&img.line_length, &img.endian);
	int i = 5;
	while (i < 50)
	{
		ft_mlx_pixel_put(&img, i, 5, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img, 0, 0);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
}