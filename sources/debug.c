/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:07:38 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/16 13:08:28 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_print_env(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("grid_width: %d\n", env->grid_width);
	printf("grid_height: %d\n", env->grid_height);
	printf("grid_values:\n");
	while (y < env->grid_height)
	{
		x = 0;
		while (x < env->grid_width)
		{
			printf("%-5d", env->grid[x][y].z_grid);
			x++;
		}
		printf("\n");
		y++;
	}
}
