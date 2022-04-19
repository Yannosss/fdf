/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:07:12 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/19 17:07:40 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit_mlx(t_env *env, char *message)
{
	if (message)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
	}
	ft_free_mlx(env);
	if (env->read_line)
	{
		free(env->read_line);
		env->read_line = NULL;
	}
	if (env->splitted_line)
	{
		ft_free_split(env->splitted_line);
		env->splitted_line = NULL;
	}
	if (env->splitted_node_value)
	{
		ft_free_split(env->splitted_node_value);
		env->splitted_node_value = NULL;
	}
	if (env->grid)
		ft_free_grid(env);
	exit(0);
}

void	ft_free_mlx(t_env *env)
{
	if (env->mlx)
	{
		if (env->window)
		{
			if (env->img.img_pt)
			{
				mlx_destroy_image(env->mlx, env->img.img_pt);
				env->img.img_pt = NULL;
				env->img.addr = NULL;
			}
			mlx_destroy_window(env->mlx, env->window);
			env->window = NULL;
		}
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->mlx = NULL;
	}
}

void	ft_free_grid(t_env *env)
{
	int	i;

	if (env->grid)
	{
		i = 0;
		while (i < env->grid_width)
		{
			if (env->grid[i])
			{
				free(env->grid[i]);
				env->grid[i] = NULL;
			}
			i++;
		}
		free(env->grid);
		env->grid = NULL;
	}
}
