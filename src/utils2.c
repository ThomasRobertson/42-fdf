/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:32:20 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 05:36:15 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	string_upper(char *str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int	open_fd(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	return (*fd);
}

void	fill_map_point(int x, int y, char *line, t_map_point **row_ptr)
{
	t_map_point	*row_tmp;
	char		*strchr_ptr;

	row_tmp = *row_ptr;
	row_tmp->x = x;
	row_tmp->y = y;
	row_tmp->z = ft_atoi(line);
	strchr_ptr = ft_strstr(line, "0x");
	if (strchr_ptr != NULL && strchr_ptr[2] != '\0')
		row_tmp->color = get_valid_color(strchr_ptr);
	else
		row_tmp->color = DEFAULT_COLOR;
}
