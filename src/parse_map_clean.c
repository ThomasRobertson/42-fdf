/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:19:51 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 05:24:51 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_point	**free_row_ptr(t_map_point **row_ptr, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(row_ptr[i]);
		i++;
	}
	free(row_ptr);
	return (NULL);
}

int	free_map_ptr(t_map_point ***map_ptr, int i, int nbr_line)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free_row_ptr(map_ptr[j], nbr_line);
		free(map_ptr[j]);
		j++;
	}
	free(map_ptr);
	return (RETURN_FAILURE);
}

int	free_get_lines(void *ptr, t_list **lines)
{
	free(ptr);
	ft_lstclear(lines, wrapper_lstclear);
	return (ft_error_return(STDOUT_FILENO, NULL, RETURN_FAILURE));
}
