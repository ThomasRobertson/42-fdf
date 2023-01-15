/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:44:56 by troberts          #+#    #+#             */
/*   Updated: 2023/01/15 17:14:54 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_lines(char *filename, t_list **lines)
{
	t_list	*line_tmp;
	char	*line_gnl;
	int		fd;

	if (open_fd(filename, &fd) == -1)
		ft_error_return(STDERR_FILENO, "get_lines: ", RETURN_FAILURE);
	while (true)
	{
		line_gnl = get_next_line(fd);
		if (line_gnl == NULL)
			break ;
		line_tmp = malloc(sizeof(*line_tmp));
		if (line_tmp == NULL)
			return (free_get_lines(line_gnl, lines));
		line_tmp->content = ft_split(line_gnl, ' ');
		free(line_gnl);
		if (line_tmp->content == NULL)
			return (free_get_lines(line_tmp, lines));
		line_tmp->next = NULL;
		ft_lstadd_back(lines, line_tmp);
	}
	close(fd);
	if (*lines == NULL)
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}

int	count_line(t_list *lines, int *nbr_lines)
{
	int		size;
	int		target_size;
	char	**content_ptr;

	target_size = 0;
	content_ptr = lines->content;
	while (content_ptr[target_size] && ft_strcmp(content_ptr[target_size], "\n") != 0)
		target_size++;
	while (lines)
	{
		size = 0;
		content_ptr = lines->content;
		while (content_ptr[size] && ft_strcmp(content_ptr[size], "\n") != 0)
			size++;
		if (size != target_size)
		{
			ft_putendl_fd("Not all lines contains the same number of row.", \
																STDERR_FILENO);
			return (RETURN_FAILURE);
		}
		lines = lines->next;
	}
	*nbr_lines = target_size;
	return (RETURN_SUCCESS);
}

t_map_point	**convert_to_t_map_point(char **line, int y, unsigned int line_len)
{
	int			x;
	t_map_point	*row_tmp;
	t_map_point	**row_ptr;

	row_ptr = malloc(sizeof(*row_ptr) * (line_len + 1));
	if (row_ptr == NULL)
		return (NULL);
	row_ptr[line_len] = NULL;
	x = 0;
	while ((unsigned int)x < line_len)
	{
		row_tmp = malloc(sizeof(*row_tmp));
		if (row_tmp == NULL)
			return (free_row_ptr(row_ptr, x));
		fill_map_point(x, y, line[x], &row_tmp);
		row_ptr[x] = row_tmp;
		x++;
	}
	return (row_ptr);
}

int	get_map_from_t_list(t_list *lines, t_map_data *map)
{
	int			i;
	t_map_point	***map_ptr;

	i = 0;
	map_ptr = malloc(sizeof(*map_ptr) * (map->nbr_row + 1));
	if (map_ptr == NULL)
		return (RETURN_FAILURE);
	map->map = map_ptr;
	map_ptr[map->nbr_row] = NULL;
	while (lines)
	{
		map_ptr[i] = convert_to_t_map_point(lines->content, i, map->nbr_line);
		if (map_ptr[i] == NULL)
			return (free_map_ptr(map_ptr, i, map->nbr_line));
		i++;
		lines = lines->next;
	}
	return (RETURN_SUCCESS);
}

int	parse_map(char *filename, t_map_data *map)
{
	t_list	*lines;

	lines = NULL;
	if (!get_lines(filename, &lines))
		return (RETURN_FAILURE);
	map->nbr_row = (unsigned int)ft_lstsize(lines);
	if (!count_line(lines, &map->nbr_line))
	{
		ft_lstclear(&lines, wrapper_lstclear);
		return (RETURN_FAILURE);
	}
	if (!get_map_from_t_list(lines, map))
	{
		ft_lstclear(&lines, wrapper_lstclear);
		return (RETURN_FAILURE);
	}
	ft_lstclear(&lines, wrapper_lstclear);
	return (RETURN_SUCCESS);
}
