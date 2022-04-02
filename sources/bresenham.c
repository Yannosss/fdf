#include "fdf.h"

void	ft_print_line(t_env *env, t_pt pt_a, t_pt pt_b, int color)
{
	float	slope;

	if (pt_a.x > pt_b.x)
		ft_print_line(env, pt_b, pt_a, color);

	slope = ((float)pt_b.y - (float)pt_a.y) / ((float)pt_b.x - (float)pt_a.x);
	if (slope > 0)
	{
		if (slope <= 1)
		{
			ft_print_line_case_1(env, pt_a, pt_b, color);
		}
		else
		{
			ft_print_line_case_3(env, pt_a, pt_b, color);
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
			ft_print_line_case_4(env, pt_a, pt_b, color);
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

// cas 1 avec inversion delta y et decrementation y au lieu d'incrementation
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

// cas 1 avec inversion x et y sur algo
void	ft_print_line_case_3(t_env *env, t_pt pt_a, t_pt pt_b, int color)
{
	int	delta_x;
	int delta_y;
	int p;

	ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
	delta_x = pt_b.x - pt_a.x;
	delta_y = pt_b.y - pt_a.y;
	p = 2 * delta_x - delta_y;
	while (pt_a.y <= pt_b.y)
	{
		if (p < 0)
		{
			p = p + 2 * delta_x;
			pt_a.y = pt_a.y + 1;
			ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
		}
		else
		{
			p = p + 2 * delta_x - 2 * delta_y;
			pt_a.y = pt_a.y + 1;
			pt_a.x = pt_a.x + 1;
			ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
		}
	}
	// ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
}

// cas 3 avec inversion delta y et decrementation y au lieu d'incrementation
// inversion conodition while et decrement y car sens inverse par rappot aux autres cas
void	ft_print_line_case_4(t_env *env, t_pt pt_a, t_pt pt_b, int color)
{
	int	delta_x;
	int delta_y;
	int p;

	ft_img_pixel_put(env , pt_a.x, pt_a.y, COLOR_BLUE);
	delta_x = pt_b.x - pt_a.x;

	delta_y = pt_b.y - pt_a.y;
	delta_y = -delta_y;
	p = 2 * delta_x - delta_y;
	while (pt_a.y >= pt_b.y)
	{
		if (p < 0)
		{
			p = p + 2 * delta_x;
			pt_a.y = pt_a.y - 1;
			ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
		}
		else
		{
			p = p + 2 * delta_x - 2 * delta_y;
			pt_a.y = pt_a.y - 1;
			pt_a.x = pt_a.x + 1;
			ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
		}
	}
	// ft_img_pixel_put(env , pt_a.x, pt_a.y, color);
}