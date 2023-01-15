/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:53:09 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 05:14:42 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (RETURN_SUCCESS);
}

int	handle_keypress(int keysum, t_hook_bundle *hook)
{
	if (keysum == XK_Escape)
		mlx_destroy_window(hook->mlx->mlx_ptr, hook->mlx->win_ptr);
	else if (keysum == XK_Down || keysum == XK_Up || keysum == XK_Right || \
															keysum == XK_Left)
		handle_move_map(keysum, hook);
	else if (keysum == XK_i || keysum == XK_I || keysum == XK_o || \
																keysum == XK_O)
		handle_zoom_map(keysum, hook);
	else if (keysum == XK_p || keysum == XK_P)
		handle_change_projection(hook);
	else if (keysum == XK_x || keysum == XK_X)
		handle_reset(hook);
	else if (keysum == XK_z || keysum == XK_Z || keysum == XK_s || \
		keysum == XK_S || keysum == XK_q || keysum == XK_Q || \
		keysum == XK_d || keysum == XK_D || keysum == XK_a || \
		keysum == XK_A || keysum == XK_e || keysum == XK_E)
		handle_rotate_map(keysum, hook);
	return (RETURN_SUCCESS);
}

int	handle_change_projection(t_hook_bundle *hook)
{
	if (hook->map->proj == para2)
		hook->map->proj = none;
	else
		hook->map->proj++;
	find_max_min(hook->map);
	render(*(hook->map), *(hook->img), *(hook->mlx));
	return (RETURN_SUCCESS);
}

int	handle_rotate_map(int keysum, t_hook_bundle *hook)
{
	if (keysum == XK_z || keysum == XK_Z)
		hook->map->rotate_value.x += 0.05;
	else if (keysum == XK_s || keysum == XK_S)
		hook->map->rotate_value.x -= 0.05;
	else if (keysum == XK_q || keysum == XK_Q)
		hook->map->rotate_value.y -= 0.05;
	else if (keysum == XK_d || keysum == XK_D)
		hook->map->rotate_value.y += 0.05;
	else if (keysum == XK_a || keysum == XK_A)
		hook->map->rotate_value.z += 0.05;
	else if (keysum == XK_e || keysum == XK_E)
		hook->map->rotate_value.z -= 0.05;
	find_max_min(hook->map);
	render(*(hook->map), *(hook->img), *(hook->mlx));
	return (RETURN_SUCCESS);
}

int	handle_move_map(int keysum, t_hook_bundle *hook)
{
	if (keysum == XK_Down)
	{
		hook->map->margin.bottom -= HORIZONTAL_INCREMENT;
		hook->map->margin.top += HORIZONTAL_INCREMENT;
	}
	else if (keysum == XK_Up)
	{
		hook->map->margin.bottom += HORIZONTAL_INCREMENT;
		hook->map->margin.top -= HORIZONTAL_INCREMENT;
	}
	else if (keysum == XK_Right)
	{
		hook->map->margin.left += HORIZONTAL_INCREMENT;
		hook->map->margin.right -= HORIZONTAL_INCREMENT;
	}
	else if (keysum == XK_Left)
	{
		hook->map->margin.left -= HORIZONTAL_INCREMENT;
		hook->map->margin.right += HORIZONTAL_INCREMENT;
	}
	render(*(hook->map), *(hook->img), *(hook->mlx));
	return (RETURN_SUCCESS);
}
