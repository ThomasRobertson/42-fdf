/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:19:51 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 04:53:53 by troberts         ###   ########.fr       */
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