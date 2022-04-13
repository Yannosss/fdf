#include "fdf.h"

#include <stdio.h>

void ft_print_env(t_env *env) // a sup dans .h
{
	printf("grid_width: %d\n", env->grid_width);
	printf("grid_height: %d\n", env->grid_height);

	printf("grid_values:\n");
	int x = 0;
	int y = 0;
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
