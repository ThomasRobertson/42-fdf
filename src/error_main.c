/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:50:56 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 04:29:51 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error_args(void)
{
	ft_putendl_fd("Usage: ./fdf [MAP]\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	error_init_windows(t_map_data map)
{
	ft_putendl_fd("Could not initialized window.\n", STDERR_FILENO);
	clean_map(&map);
	return (EXIT_FAILURE);
}

int	error_new_image(t_mlx mlx, t_map_data map)
{
	ft_putendl_fd("Could not create new image.", STDERR_FILENO);
	clean_map(&map);
	return (clean_window_display(mlx, EXIT_FAILURE));
}

int	error_parse(void)
{
	ft_putendl_fd("Could not parse map.", STDERR_FILENO);
	return (EXIT_FAILURE);
}