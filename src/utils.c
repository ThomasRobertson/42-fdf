/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:26:58 by troberts          #+#    #+#             */
/*   Updated: 2022/10/24 21:19:48 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	*return_ptr_point(unsigned int x, unsigned int y, t_map_data map)
{
	t_map_point	***map_ptr;

	if (x >= map.nbr_line || y >= map.nbr_row)
		return (NULL);
	map_ptr = map.map;
	return (map_ptr[y][x]);
}

void	wrapper_lstclear(void *ptr)
{
	ft_free_double_ptr((char **)ptr);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (RETURN_SUCCESS);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;
	int		i;

	if (x > WIN_W || y > WIN_H)
		return ;
	i = img->bits_per_pixel - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}
