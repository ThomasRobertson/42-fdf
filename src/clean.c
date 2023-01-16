/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:42:31 by troberts          #+#    #+#             */
/*   Updated: 2023/01/17 00:07:02 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	clean_window_display(t_mlx mlx, int return_code)
{
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx.win_ptr = NULL;
	return (clean_display(mlx, return_code));
}

int	clean_display(t_mlx mlx, int return_code)
{
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (return_code);
}

void	clean_map(t_map_data *map)
{
	t_map_point	***map_ptr;
	int			i;
	int			j;

	map_ptr = map->map;
	i = 0;
	while (i < map->nbr_row)
	{
		j = 0;
		while (j < map->nbr_line)
		{
			free(map_ptr[i][j]);
			j++;
		}
		free(map_ptr[i]);
		i++;
	}
	free(map_ptr);
}

int	clean_exit(t_mlx mlx, t_img img, t_map_data *map)
{
	mlx_destroy_image(mlx.mlx_ptr, img.img_ptr);
	clean_map(map);
	clean_display(mlx, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
