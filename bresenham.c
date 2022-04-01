#include "fdf.h"

void	ft_print_line(t_env *env, t_pt pt_a, t_pt pt_b, int color)
{
	float	slope;

	if (pt_a.x > pt_b.x)
		ft_print_line(env, pt_b, pt_a, color);

	slope = ((float)pt_b.y - (float)pt_a.y) / ((float)pt_b.x - (float)pt_a.x);
	printf("slope %f\n", slope);
	if (slope > 0)
	{
		if (slope <= 1)
		{
			ft_print_line_case_1(env, pt_a, pt_b, color);
		}
		else
		{

		}
	}
	else
	{
		if (slope >= -1)
		{
			ft_print_line_case_2(env, pt_a, pt_b, color);
		}
		else
		{

		}
	}


}

void	ft_print_line_case_1(t_env *env, t_pt pt_a, t_pt pt_b, int color)
{
	int	delta_x;
	int delta_y;
	int p;

	ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
	delta_x = pt_b.x - pt_a.x;
	delta_y = pt_b.y - pt_a.y;
	p = 2 * delta_y - delta_x;
	while (pt_a.x <= pt_b.x)
	{
		if (p < 0)
		{
			p = p + 2 * delta_y;
			pt_a.x = pt_a.x + 1;
			ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
		}
		else
		{
			p = p + 2 * delta_y - 2 * delta_x;
			pt_a.x = pt_a.x + 1;
			pt_a.y = pt_a.y + 1;
			ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
		}
	}
	// ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
}

void	ft_print_line_case_2(t_env *env, t_pt pt_a, t_pt pt_b, int color)
{
	int	delta_x;
	int delta_y;
	int p;

	// pt_b.y = pt_b.y - 2 * (pt_b.y - pt_a.y);
	ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
	delta_x = pt_b.x - pt_a.x;
	delta_y = pt_b.y - pt_a.y;
	delta_y = -delta_y;
	p = 2 * delta_y - delta_x;
	while (pt_a.x <= pt_b.x)
	{
		if (p < 0)
		{
			p = p + 2 * delta_y;
			pt_a.x = pt_a.x + 1;
			ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
		}
		else
		{
			p = p + 2 * delta_y - 2 * delta_x;
			pt_a.x = pt_a.x + 1;
			pt_a.y = pt_a.y - 1;
			ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
		}
	}
	// ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
}