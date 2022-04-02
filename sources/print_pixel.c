#include "fdf.h"

void	ft_img_pixel_put(t_env *env, int x, int y, int color)
{
	char    *pixel;
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;

    pixel = env->img.addr + (y * env->img.line_len + x * (env->img.bpp / 8));
	*(int *)pixel = color;
}