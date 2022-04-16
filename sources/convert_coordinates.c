/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:24:31 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/16 11:35:28 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_convert_grid_coordinates(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < env->grid_width)
	{
		y = 0;
		while (y < env->grid_height)
		{
			ft_convert_node_coordinate(env, &(env->grid[x][y]));
			y++;
		}
		x++;
	}
}

// ordre transfomations :
//		zoom
//		rotation
//		transformation isometrique (2D -> 3D)
//		translation
void	ft_convert_node_coordinate(t_env *env, t_node *node)
{
	ft_convert_node_coordinate_zoom_rot(env, node);
	ft_convert_node_coordinate_iso_transl(env, node);
}

void	ft_convert_node_coordinate_zoom_rot(t_env *env, t_node *node)
{
	float	r;
	float	t;
	float	p;

	r = env->trim_r * 3.14 / 180;
	t = env->trim_th * 3.14 / 180;
	p = env->trim_p * 3.14 / 180;
	node->x_grid_zoom = node->x_grid * env->trim_zoom;
	node->y_grid_zoom = node->y_grid * env->trim_zoom;
	node->z_grid_zoom = node->z_grid * env->trim_zoom;
	node->x_rot
		= node->x_grid_zoom * (cos(r) * cos(p) - sin(r) * cos(t) * sin(p))
		+ node->y_grid_zoom * (-1 * cos(r) * sin(p) - sin(r) * cos(t) * cos(p))
		+ node->z_grid_zoom * (sin(r) * sin(t));
	node->y_rot
		= node->x_grid_zoom * (sin(r) * cos(p) + cos(r) * cos(t) * sin(p))
		+ node->y_grid_zoom * (-1 * sin(r) * sin(p) + cos(r) * cos(t) * cos(p))
		+node->z_grid_zoom * (-1 * cos(r) * sin(t));
	node->z_rot
		= node->x_grid_zoom * (sin(t) * sin (p))
		+ node->y_grid_zoom * (sin(t) * cos (p))
		+ node->z_grid_zoom * cos (t);
}

void	ft_convert_node_coordinate_iso_transl(t_env *env, t_node *node)
{
	node->x_screen = (node->x_rot - node->y_rot) * cos(0.523599)
		+ WINDOW_WIDTH / 2;
	node->y_screen = (node->x_rot + node->y_rot) * sin(0.523599)
		- node->z_rot + WINDOW_HEIGHT / 2;
	node->x_screen = node->x_screen + env->trim_x;
	node->y_screen = node->y_screen + env->trim_y;
}
