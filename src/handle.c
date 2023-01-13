/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:53:09 by troberts          #+#    #+#             */
/*   Updated: 2023/01/13 14:32:36 by troberts         ###   ########.fr       */
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

int	handle_zoom_map(int keysum, t_hook_bundle *hook)
{
	if (keysum == XK_i || keysum == XK_I)
	{
		hook->map->margin.bottom -= HORIZONTAL_INCREMENT;
		hook->map->margin.top -= HORIZONTAL_INCREMENT;
		hook->map->margin.left -= HORIZONTAL_INCREMENT;
		hook->map->margin.right -= HORIZONTAL_INCREMENT;
	}
	else if (keysum == XK_o || keysum == XK_O)
	{
		hook->map->margin.bottom += HORIZONTAL_INCREMENT;
		hook->map->margin.top += HORIZONTAL_INCREMENT;
		hook->map->margin.left += HORIZONTAL_INCREMENT;
		hook->map->margin.right += HORIZONTAL_INCREMENT;
	}
	render(*(hook->map), *(hook->img), *(hook->mlx));
	return (RETURN_SUCCESS);
}

int	handle_reset(t_hook_bundle *hook)
{
	hook->map->rotate_value.x = DEFAULT_ROTATE;
	hook->map->rotate_value.y = DEFAULT_ROTATE;
	hook->map->rotate_value.z = DEFAULT_ROTATE;
	hook->map->margin.bottom = BOTTOM_MARGIN;
	hook->map->margin.top = TOP_MARGIN;
	hook->map->margin.left = LEFT_MARGIN;
	hook->map->margin.right = RIGHT_MARGIN;
	hook->map->proj = DEFAULT_PROJ;
	return (RETURN_SUCCESS);
}
