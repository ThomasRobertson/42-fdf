/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:29:53 by troberts          #+#    #+#             */
/*   Updated: 2022/10/04 15:37:53 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../libft/include/libft.h"

# include <X11/X.h>
# include <X11/keysym.h>

# define WIN_W 800
# define WIN_H 400

# define RETURN_SUCCESS 0
# define RETURN_FAILURE 1

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_color {
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

// CLEAN
int		clean_display(t_mlx mlx, int return_code);
int		clean_window_display(t_mlx mlx, int return_code);

// COLOR
int		convert_to_argb(int t, int r, int g, int b);

int		get_a(int argb);
int		get_r(int argb);
int		get_g(int argb);
int		get_b(int argb);

//HANDLE
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_mlx *mlx);

// INIT
int		init_window(t_mlx *mlx);

// UTILS
int		ft_mlx_new_image(t_mlx mlx, t_img *img);
void	ft_mlx_pixel_put(t_img *data, int x, int y, int color);
int		close_window(t_mlx *vars);

#endif