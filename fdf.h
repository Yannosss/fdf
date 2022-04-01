#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define MLX_ERROR 1

# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000

typedef struct s_img
{
	void	*img_pt;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_env
{
	void	*mlx;
	void	*window;
	t_img	img;
}	t_env;

typedef struct s_pt
{
	int	x;
	int	y;
}	t_pt;

// main
int		ft_draw(t_env *env);
void	ft_img_pixel_put(t_env *env, int x, int y, int color);

// envent manager
void	ft_event_manager(t_env *env);
// int	handle_no_event(void *data);
int	ft_keypress_manager(int keysym, t_env *env);

// bresenham
void	ft_print_line(t_env *env, t_pt pt_a, t_pt pt_b, int color);
void	ft_print_line_case_1(t_env *env, t_pt pt_a, t_pt pt_b, int color);
void	ft_print_line_case_2(t_env *env, t_pt pt_a, t_pt pt_b, int color);

// exit
void	ft_exit_mlx(t_env *env);

#endif