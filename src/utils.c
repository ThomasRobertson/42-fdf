/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:26:58 by troberts          #+#    #+#             */
/*   Updated: 2022/10/03 21:01:27 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (RETURN_SUCCESS);
}

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	size_t	offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
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
