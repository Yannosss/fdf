/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:13:43 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/16 12:10:45 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# include <stdio.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define XY_SCALE_FACTOR 10
# define Z_SCALE_FACTOR 2

# define MLX_ERROR 1
# define ON_DESTROY 17

# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_ORANGE 0xFF8000
# define COLOR_BLACK 0x000000

typedef struct s_img
{
	void	*img_pt;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_node
{
	int	x_grid;
	int	y_grid;
	int	z_grid;

	int	x_grid_zoom;
	int	y_grid_zoom;
	int	z_grid_zoom;

	int	x_rot;
	int	y_rot;
	int	z_rot;

	int	x_screen;
	int	y_screen;
}	t_node;

typedef struct s_env
{
	char	*file_name;
	void	*mlx;
	void	*window;
	t_img	img;
	char	*read_line;
	char	**splitted_line;
	int		grid_width;
	int		grid_height;
	t_node	**grid;
	int		trim_x;
	int		trim_y;
	int		trim_r;
	int		trim_th;
	int		trim_p;
	float	trim_zoom;
	int		color_list[5];
	int		indice_chosen_color;
	int		chosen_color;
}	t_env;

// main
int		ft_draw_test_lines(t_env *env);
void	ft_img_pixel_put(t_env *env, int x, int y, int color);

// parsing input
void	ft_parse_input(t_env *env, char **argv);
void	ft_get_grid_size(t_env *env);
int		ft_nb_of_elements_on_line(t_env *env, char *line);
void	ft_get_grid_values(t_env *env);

// envent manager
void	ft_event_manager(t_env *env);
int		ft_exit_cross_pressed(t_env *env);
int		ft_keypress_manager(int key, t_env *env);

// envent fonctions 1
void	ft_escape_manager(int key, t_env *env);
void	ft_translation_trim_manager(int key, t_env *env);
void	ft_zoom_trim_manager(int key, t_env *env);
void	ft_color_trim_manager(int key, t_env *env);

// envent fonctions 2
void	ft_rotation_trim_manager(int key, t_env *env);
void	ft_rotation_trim_manager_r(int key, t_env *env);
void	ft_rotation_trim_manager_th(int key, t_env *env);
void	ft_rotation_trim_manager_p(int key, t_env *env);

// bresenham
void	ft_print_line(t_env *env, t_node pt_a, t_node pt_b, int color);
void	ft_print_line_case_1(t_env *env, t_node pt_a, t_node pt_b, int color);
void	ft_print_line_case_2(t_env *env, t_node pt_a, t_node pt_b, int color);
void	ft_print_line_case_3(t_env *env, t_node pt_a, t_node pt_b, int color);
void	ft_print_line_case_4(t_env *env, t_node pt_a, t_node pt_b, int color);

// init
void	ft_init_env(t_env *env);
void	ft_init_part_1(t_env *env);
void	ft_init_part_2(t_env *env);
void	ft_init_mlx(t_env *env);
void	ft_init_grid(t_env *env);

// convert coordinate
void	ft_convert_grid_coordinates(t_env *env);
void	ft_convert_node_coordinate(t_env *env, t_node *node);
void	ft_convert_node_coordinate_zoom_rot(t_env *env, t_node *node);
void	ft_convert_node_coordinate_iso_transl(t_env *env, t_node *node);

// draw grid
void	ft_draw_grid(t_env *env);
void	ft_draw_black_screen(t_env *env);
void	ft_draw_horizontal_lines(t_env *env);
void	ft_draw_vertical_lines(t_env *env);

// exit
void	ft_exit_mlx(t_env *env, char *message);
void	ft_free_mlx(t_env *env);
void	ft_free_grid(t_env *env);

#endif
