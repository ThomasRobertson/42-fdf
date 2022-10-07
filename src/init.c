/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:38:29 by troberts          #+#    #+#             */
/*   Updated: 2022/10/07 15:55:39 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (RETURN_FAILURE);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "Hello world!");
	if (mlx->win_ptr == NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return (RETURN_FAILURE);
	}
	return (RETURN_SUCCESS);
}

int	ft_mlx_new_image(t_mlx mlx, t_img *img)
{
	img->img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_W, WIN_H);
	if (img->img_ptr == NULL)
		return (RETURN_FAILURE);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, \
										&img->line_length, &img->endian);
	if (img->addr == NULL)
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}
