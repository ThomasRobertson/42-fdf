/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:06:28 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 17:31:54 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_string_put(t_mlx mlx, int x, int y, char *str)
{
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, x, y, DEFAULT_COLOR, str);
}

void	draw_menu(t_mlx mlx)
{
	int	y;

	y = 250;
	ft_string_put(mlx, 65, y += 20, "CONTROL");
	ft_string_put(mlx, 15, y += 35, "Move:");
	ft_string_put(mlx, 57, y += 25, "Arrows");
	ft_string_put(mlx, 15, y += 30, "Zoom:");
	ft_string_put(mlx, 57, y += 25, "O - Zoom out");
	ft_string_put(mlx, 57, y += 25, "I - Zoom in");
	ft_string_put(mlx, 15, y += 30, "Rotate:");
	ft_string_put(mlx, 57, y += 25, "Q-E-W-S-A-D");
	ft_string_put(mlx, 15, y += 30, "Change projection:");
	ft_string_put(mlx, 57, y += 25, "P");
	ft_string_put(mlx, 15, y += 30, "Reset view:");
	ft_string_put(mlx, 57, y += 25, "X");
	ft_string_put(mlx, 15, y += 30, "Exit:");
	ft_string_put(mlx, 57, y += 25, "ESC");
}
