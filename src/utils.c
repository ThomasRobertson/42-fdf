/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:26:58 by troberts          #+#    #+#             */
/*   Updated: 2022/11/20 16:19:34 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	*return_ptr_point(int x, int y, t_map_data map)
{
	t_map_point	***map_ptr;

	if (x >= map.nbr_line || y >= map.nbr_row)
		return (NULL);
	map_ptr = map.map;
	return (map_ptr[y][x]);
}

t_map_point	return_point(int x, int y, t_map_data map)
{
	t_map_point	***map_ptr;

	if (y >= map.nbr_row)
		y = map.nbr_row - 1;
	if (y < 0)
		y = 0;
	if (x >= map.nbr_line)
		x = map.nbr_row - 1;
	if (x < 0)
		x = 0;
	map_ptr = map.map;
	return (*(map_ptr[y][x]));
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

void	swap(t_map_point *a, t_map_point *b)
{
	t_map_point	c;

	c = *a;
	*a = *b;
	*b = c;
}
