/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:14:01 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/19 20:14:04 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_grid_line(t_env *env, int y)
{
	int	x;

	x = 0;
	while (x < env->grid_width)
	{
		env->grid[x][y].x_grid = (x - env->grid_width / 2)
			* XY_SCALE_FACTOR;
		env->grid[x][y].y_grid = (y - env->grid_height / 2)
			* XY_SCALE_FACTOR;
		env->splitted_node_value = ft_split(env->splitted_line[x], ',');
		if (!env->splitted_node_value)
			ft_exit_mlx(env, "error: split function");
		ft_get_splitted_node_value(env, x, y);
		ft_free_split(env->splitted_node_value);
		env->splitted_node_value = NULL;
		x++;
	}
}

void	ft_get_splitted_node_value(t_env *env, int x, int y)
{
	if (ft_splitlen(env->splitted_node_value) == 1)
	{
		env->grid[x][y].z_grid = ft_atoi(env->splitted_node_value[0])
			* Z_SCALE_FACTOR;
		env->grid[x][y].color = COLOR_WHITE;
	}
	else if (ft_splitlen(env->splitted_node_value) == 2)
	{
		env->grid[x][y].z_grid = ft_atoi(env->splitted_node_value[0])
			* Z_SCALE_FACTOR;
		env->grid[x][y].color = ft_hexastr_to_int(env,
				env->splitted_node_value[1]);
	}
	else
		ft_exit_mlx(env, "error: invalid map");
}

int	ft_hexastr_to_int(t_env *env, char *str)
{
	int	i;
	int	int_value;

	if (str[0] != '0' || str[1] != 'x')
		ft_exit_mlx(env, "error: invalid map > color not hexa");
	i = 2;
	int_value = 0;
	while (str[i] && str[i] != '\n')
	{
		int_value = 16 * int_value + ft_hexa_value(env, str[i]);
		i++;
	}
	return (int_value);
}

int	ft_hexa_value(t_env *env, char c)
{
	if (c == 'A' || c == 'a')
		return (10);
	else if (c == 'B' || c == 'b')
		return (11);
	else if (c == 'C' || c == 'c')
		return (12);
	else if (c == 'D' || c == 'd')
		return (13);
	else if (c == 'E' || c == 'e')
		return (14);
	else if (c == 'F' || c == 'f')
		return (15);
	else if (c >= '0' && c <= '9')
		return ((int)c - 48);
	else
		ft_exit_mlx(env, "error: invalid map > color not hexa");
	return (0);
}
