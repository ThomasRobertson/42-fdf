/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:29:53 by troberts          #+#    #+#             */
/*   Updated: 2022/10/19 14:43:52 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "typedef_fdf.h"
# include "../libft/include/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <X11/X.h>
# include <X11/keysym.h>

# define WIN_W 612
# define WIN_H 612

# define DEFAULT_COLOR 0xFFFFFFFF

typedef struct s_map_point {
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}			t_map_point;

typedef struct s_map_data {
	t_map_point		***map;
	unsigned int	nbr_line;
	unsigned int	nbr_row;
}					t_map_data;

typedef struct s_draw_line {
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	unsigned int	color;
}			t_draw_line;

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
int			clean_display(t_mlx mlx, int return_code);
int			clean_window_display(t_mlx mlx, int return_code);

// COLOR
int			convert_to_argb(int t, int r, int g, int b);

int			get_a(int argb);
int			get_r(int argb);
int			get_g(int argb);
int			get_b(int argb);

//DRAW_LINE
void		drawline(t_img img, t_draw_line line);

//HANDLE
int			handle_no_event(void *data);
int			handle_keypress(int keysym, t_mlx *mlx);

// INIT
int			init_window(t_mlx *mlx);

// PARSE MAP
int			parse_map(char *filename, t_map_data *map);

// UTILS
int			ft_mlx_new_image(t_mlx mlx, t_img *img);
void		ft_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
int			close_window(t_mlx *vars);
void		wrapper_lstclear(void *ptr);
t_map_point	*return_ptr_point(unsigned int x, unsigned int y, t_map_data map);

#endif