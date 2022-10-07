/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:53:09 by troberts          #+#    #+#             */
/*   Updated: 2022/10/07 16:14:53 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (RETURN_SUCCESS);
}

int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (RETURN_SUCCESS);
}
