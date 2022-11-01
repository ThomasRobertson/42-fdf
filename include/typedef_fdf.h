/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef_fdf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:02:18 by troberts          #+#    #+#             */
/*   Updated: 2022/10/10 19:06:44 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_FDF_H
# define TYPEDEF_FDF_H

# define T_LIST

typedef struct s_list
{
	char			**content;
	struct s_list	*next;
}					t_list;

#endif