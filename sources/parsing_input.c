/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:56:56 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/18 23:19:19 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse_input(t_env *env, char **argv)
{
	env->file_name = argv[1];
	ft_get_grid_size(env);
	ft_init_grid(env);
	ft_get_grid_values(env);
}

void	ft_get_grid_size(t_env *env)
{
	int	fd_file;

	fd_file = open(env->file_name, O_RDONLY);
	if (fd_file == -1)
		ft_exit_mlx(env, "error: opening file");
	env->read_line = get_next_line(fd_file);
	if (!env->read_line)
		ft_exit_mlx(env, "error: gnl function");
	env->grid_width = ft_nb_of_elements_on_line(env, env->read_line);
	env->grid_height = 0;
	while (env->read_line)
	{
		if (env->grid_width != ft_nb_of_elements_on_line(env, env->read_line))
			ft_exit_mlx(env, "error: invalid map > different line size");
		env->grid_height = env->grid_height + 1;
		free(env->read_line);
		env->read_line = get_next_line(fd_file);
	}
	close (fd_file);
}

int	ft_nb_of_elements_on_line(t_env *env, char *line)
{
	int	nb_of_elements;
	int	previous_is_space;

	previous_is_space = 1;
	nb_of_elements = 0;
	while (*line && *line != '\n')
	{
		if (!ft_isalnum(*line) && *line != '-' && *line != ' ' && *line != ',' )
		 	ft_exit_mlx(env, "error: invalid map > character not accepted");
		if (*line == ' ')
			previous_is_space = 1;
		else if (previous_is_space)
		{
			nb_of_elements++;
			previous_is_space = 0;
		}
		line++;
	}
	return (nb_of_elements);
}

void	ft_get_grid_values(t_env *env)
{
	int	fd_file;
	int	y;

	fd_file = open(env->file_name, O_RDONLY);
	if (fd_file == -1)
		ft_exit_mlx(env, "error: opening file");
	y = 0;
	while (y < env->grid_height)
	{
		env->read_line = get_next_line(fd_file);
		env->splitted_line = ft_split(env->read_line, ' ');
		if (!env->splitted_line)
			ft_exit_mlx(env, "error: split function");
		ft_get_grid_line(env, y);
		ft_free_split(env->splitted_line);
		env->splitted_line = NULL;
		free(env->read_line);
		env->read_line = NULL;
		y++;
	}
	close (fd_file);
}

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
		env->grid[x][y].z_grid = ft_atoi(env->splitted_line[x])
			* Z_SCALE_FACTOR;

		env->splitted_node_value = ft_split(env->splitted_line[x], ',');
		if (!env->splitted_node_value)
			ft_exit_mlx(env, "error: split function");
		printf("split len %ld\n", ft_splitlen(env->splitted_node_value));
		printf("split 1 %s\n", env->splitted_node_value[0]);
		printf("split 2 %s\n", env->splitted_node_value[1]);

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
			env->grid[x][y].color = ft_hexastr_to_int(env, env->splitted_node_value[1]);
			printf("color hex : %s\n", env->splitted_node_value[1]);
			printf("color int : %d\n", ft_hexastr_to_int(env, env->splitted_node_value[1]));
		}
		x++;
	}
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
