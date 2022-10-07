/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:42:31 by troberts          #+#    #+#             */
/*   Updated: 2022/10/07 16:13:34 by troberts         ###   ########.fr       */
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
