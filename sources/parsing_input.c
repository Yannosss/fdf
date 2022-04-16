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
	int fd_file;

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
	int nb_of_elements;
	int previous_is_space;

	previous_is_space = 1;
	nb_of_elements = 0;
	while (*line && *line != '\n')
	{
		if (!ft_isdigit(*line) && *line != '-' && *line != ' ')
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

void ft_get_grid_values(t_env *env)
{
	int fd_file;
	int	x;
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
		x = 0;
		while (x < env->grid_width)
		{
			env->grid[x][y].x_grid = (x - env->grid_width / 2) * XY_SCALE_FACTOR;
			env->grid[x][y].y_grid = (y - env->grid_height / 2) * XY_SCALE_FACTOR;
			env->grid[x][y].z_grid = ft_atoi(env->splitted_line[x]) * Z_SCALE_FACTOR;
			x++;
		}
		ft_free_split(env->splitted_line);
		env->splitted_line = NULL;
		free(env->read_line);
		env->read_line = NULL;
		y++;
	}
	close (fd_file);
}
