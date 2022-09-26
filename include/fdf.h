/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:29:53 by troberts          #+#    #+#             */
/*   Updated: 2022/09/25 20:47:17 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../libft/include/libft.h"

# define RETURN_SUCCESS EXIT_SUCCESS
# define RETURN_FAILURE EXIT_FAILURE

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_color {
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

// COLOR
int		convert_to_argb(int t, int r, int g, int b);

int		get_a(int argb);
int		get_r(int argb);
int		get_g(int argb);
int		get_b(int argb);

// UTILS
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(t_mlx *vars);

#endif