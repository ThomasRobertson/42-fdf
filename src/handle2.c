/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:53:09 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 05:14:24 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	render(*(hook->map), *(hook->img), *(hook->mlx));
	return (RETURN_SUCCESS);
}

int	handle_close(t_hook_bundle *hook)
{
	clean_exit(*(hook->mlx), *(hook->img), hook->map);
	exit(EXIT_SUCCESS);
}
