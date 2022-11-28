/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:42:31 by troberts          #+#    #+#             */
/*   Updated: 2022/11/28 19:22:22 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	clean_window_display(t_mlx mlx, int return_code)
{
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
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
