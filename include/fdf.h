/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:29:53 by troberts          #+#    #+#             */
/*   Updated: 2022/12/23 21:47:58 by troberts         ###   ########.fr       */
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
# include <math.h>
# include <limits.h>
# include <float.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define M_PI 3.14159265358979323846

# define WIN_W 900
# define WIN_H 900

# define LEFT_MARGIN 0.10
# define RIGHT_MARGIN 0.10
# define TOP_MARGIN 0.10
# define BOTTOM_MARGIN 0.10
# define HORIZONTAL_INCREMENT 0.05
# define LATERAL_INCREMENT 0.05

# define Z_RESOLUTION 2
# define ANGLE 30
# define DEFAULT_COLOR 0xFF93A1A1
# define DEFAULT_COLOR_BG 0xFF073642
# define HIGH_COLOR 0xFFF9D999
# define LOW_COLOR 0xFF28243C
# define DEFAULT_PROJ 1
# define TRANSPARENCY 255

typedef struct s_margin {
	double	left;
	double	right;
	double	top;
	double	bottom;
}			t_margin;

typedef enum e_proj
{
	none = 0,
	iso = 1,
	para = 2
}	t_proj;

typedef struct s_map_point {
	double			x;
	double			y;
	int				z;
	unsigned int	color;
}					t_map_point;

typedef struct s_min_max {
	double	min;
	double	max;
}			t_min_max;

typedef struct s_min_max_z {
	int	min;
	int	max;
}		t_min_max_z;

typedef struct s_map_data {
	t_map_point		***map;
	int				nbr_line;
	int				nbr_row;
	double			angle;
	t_proj			proj;
	t_min_max		x;
	t_min_max		y;
	t_min_max_z		z;
	t_bool			overwrite_color;
	t_margin		margin;
}					t_map_data;

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

typedef struct s_hook_bundle {
	t_map_data	*map;
	t_mlx		*mlx;
	t_img		*img;
}				t_hook_bundle;

typedef struct s_color {
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

// CLEAN
int				clean_display(t_mlx mlx, int return_code);
int				clean_window_display(t_mlx mlx, int return_code);
void			clean_map(t_map_data *map);

// COLOR
void			fill_background(t_img img);
unsigned int	get_color_gradient(t_map_point start, t_map_point end, \
															t_map_point point);
unsigned int	get_valid_color(char *strchr_ptr);
int				convert_to_argb(t_color color);
unsigned int	get_fixed_color_gradient(int line_len, int i, t_map_point start, t_map_point end);
unsigned int	get_color(t_map_point start, t_map_point end, \
											t_map_point point, t_map_data map);

// COLOR RGBA
int				get_a(int argb);
int				get_r(int argb);
int				get_g(int argb);
int				get_b(int argb);

// CONVERT 3D
t_map_point		convert_point(t_map_point point, t_map_data map);
t_map_point		convert_iso_point(t_map_point point, t_map_data map);

//DRAW_LINE
void			drawline(t_img img, t_map_point const *start, \
									t_map_point const *end, t_map_data map);
void			bresenham_fixed_color(t_img img, t_map_point start, \
												t_map_point end, int line_len);
void			bresenham_real_color(t_img img, t_map_point start, \
															t_map_point end);
int				bresenham_counter(t_map_point start, t_map_point end);

// DRAW_MAP
void			ft_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
t_map_point		get_start_end_point_x(t_map_data map, t_map_point *start, \
												int x, int y);
t_map_point		get_start_end_point_y(t_map_data map, t_map_point *start, \
												int x, int y);
void			draw_map(t_map_data map, t_img img);
void			process_start_and_point(t_map_data map, t_map_point *start, \
															t_map_point *end);

// ERROR MAIN
int				error_args(void);
int				error_init_windows(t_map_data map);
int				error_new_image(t_mlx mlx, t_map_data map);

// FIND MIN MAX
void			find_max_min_x(t_map_data *map);
void			find_max_min_y(t_map_data *map);
void			find_max_min_z(t_map_data *map);
void			find_max_min(t_map_data *map);

//HANDLE
int				handle_no_event(void *data);
int				handle_keypress(int keysym, t_hook_bundle *hook);
int				handle_move_map(int keysum, t_hook_bundle *hook);
int				handle_zoom_map(int keysum, t_hook_bundle *hook);
int				handle_change_projection(t_hook_bundle *hook);

// INIT
int				init_window(t_mlx *mlx);
int				ft_mlx_new_image(t_mlx mlx, t_img *img);

// MATH
double			convert_to_rad(double deg);

// PARSE MAP
int				parse_map(char *filename, t_map_data *map);

// PROCESS MAP
t_map_point		offset_point(t_map_point point, t_map_data map);
t_map_point		normalize_point(t_map_point point, t_map_data map);

// RENDER
void			first_render(t_map_data *map, t_img img, t_mlx mlx);
void			render(t_map_data map, t_img img, t_mlx mlx);

// UTILS
int				close_window(t_mlx *vars);
void			wrapper_lstclear(void *ptr);
t_map_point		*return_ptr_point(int x, int y, t_map_data map);
t_map_point		return_point(int x, int y, t_map_data map);
void			swap(t_map_point *a, t_map_point *b);

// UTILS2
void			string_upper(char *str);

#endif
