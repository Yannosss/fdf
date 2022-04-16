/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:17:22 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/16 11:23:54 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_line(t_env *env, t_node pt_a, t_node pt_b, int color)
{
	float	slope;

	if (pt_a.x_screen > pt_b.x_screen)
		ft_print_line(env, pt_b, pt_a, color);
	slope = ((float)pt_b.y_screen - (float)pt_a.y_screen)
		/ ((float)pt_b.x_screen - (float)pt_a.x_screen);
	if (slope > 0)
	{
		if (slope <= 1)
			ft_print_line_case_1(env, pt_a, pt_b, color);
		else
			ft_print_line_case_3(env, pt_a, pt_b, color);
	}
	else
	{
		if (slope >= -1)
			ft_print_line_case_2(env, pt_a, pt_b, color);
		else
			ft_print_line_case_4(env, pt_a, pt_b, color);
	}
}

void	ft_print_line_case_1(t_env *env, t_node pt_a, t_node pt_b, int color)
{
	int	delta_x;
	int	delta_y;
	int	p;

	ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
	delta_x = pt_b.x_screen - pt_a.x_screen;
	delta_y = pt_b.y_screen - pt_a.y_screen;
	p = 2 * delta_y - delta_x;
	while (pt_a.x_screen <= pt_b.x_screen)
	{
		if (p < 0)
		{
			p = p + 2 * delta_y;
			pt_a.x_screen = pt_a.x_screen + 1;
			ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
		}
		else
		{
			p = p + 2 * delta_y - 2 * delta_x;
			pt_a.x_screen = pt_a.x_screen + 1;
			pt_a.y_screen = pt_a.y_screen + 1;
			ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
		}
	}
}

// cas 1 avec inversion delta y et decrementation y au lieu d'incrementation
void	ft_print_line_case_2(t_env *env, t_node pt_a, t_node pt_b, int color)
{
	int	delta_x;
	int	delta_y;
	int	p;

	ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
	delta_x = pt_b.x_screen - pt_a.x_screen;
	delta_y = pt_b.y_screen - pt_a.y_screen;
	delta_y = -delta_y;
	p = 2 * delta_y - delta_x;
	while (pt_a.x_screen <= pt_b.x_screen)
	{
		if (p < 0)
		{
			p = p + 2 * delta_y;
			pt_a.x_screen = pt_a.x_screen + 1;
			ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
		}
		else
		{
			p = p + 2 * delta_y - 2 * delta_x;
			pt_a.x_screen = pt_a.x_screen + 1;
			pt_a.y_screen = pt_a.y_screen - 1;
			ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
		}
	}
}

// cas 1 avec inversion x et y sur algo
void	ft_print_line_case_3(t_env *env, t_node pt_a, t_node pt_b, int color)
{
	int	delta_x;
	int	delta_y;
	int	p;

	ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
	delta_x = pt_b.x_screen - pt_a.x_screen;
	delta_y = pt_b.y_screen - pt_a.y_screen;
	p = 2 * delta_x - delta_y;
	while (pt_a.y_screen <= pt_b.y_screen)
	{
		if (p < 0)
		{
			p = p + 2 * delta_x;
			pt_a.y_screen = pt_a.y_screen + 1;
			ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
		}
		else
		{
			p = p + 2 * delta_x - 2 * delta_y;
			pt_a.y_screen = pt_a.y_screen + 1;
			pt_a.x_screen = pt_a.x_screen + 1;
			ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
		}
	}
}

// cas 3 avec inversion delta y et decrementation y au lieu d'incrementation
// inversion conodition while et decrement y car
// sens inverse par rappot aux autres cas
void	ft_print_line_case_4(t_env *env, t_node pt_a, t_node pt_b, int color)
{
	int	delta_x;
	int	delta_y;
	int	p;

	ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, COLOR_BLUE);
	delta_x = pt_b.x_screen - pt_a.x_screen;
	delta_y = pt_b.y_screen - pt_a.y_screen;
	delta_y = -delta_y;
	p = 2 * delta_x - delta_y;
	while (pt_a.y_screen >= pt_b.y_screen)
	{
		if (p < 0)
		{
			p = p + 2 * delta_x;
			pt_a.y_screen = pt_a.y_screen - 1;
			ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
		}
		else
		{
			p = p + 2 * delta_x - 2 * delta_y;
			pt_a.y_screen = pt_a.y_screen - 1;
			pt_a.x_screen = pt_a.x_screen + 1;
			ft_img_pixel_put(env, pt_a.x_screen, pt_a.y_screen, color);
		}
	}
}
