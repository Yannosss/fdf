#include "fdf.h"

void	ft_parse_input(t_env *env, char **argv)
{
	env->file_name = ft_strdup(argv[1]);

	ft_get_grid_size(env);
	ft_init_grid(env);
	ft_get_grid_values(env);
	ft_print_env(env);


}


void	ft_get_grid_size(t_env *env)
{
	int fd_file;

	fd_file = open(env->file_name, O_RDONLY);
	if (fd_file == -1)
		ft_exit_mlx(env);
	env->read_line = get_next_line(fd_file);
	if (!env->read_line)
		ft_exit_mlx(env);
	env->grid_width = ft_nb_of_elements_on_line(env, env->read_line);

	env->grid_height = 0;
	while (env->read_line)
	{

		env->grid_height = env->grid_height + 1;
		free(env->read_line);
		env->read_line = get_next_line(fd_file);
		// ajout check si la ligne fait bien la meme taille que les autres lignes
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
		if (!ft_isdigit(*line) && *line != ' ')
		{
			// printf("char = '%c'\n", *line);
			ft_putstr_fd("Invalid map\n", 2);
			ft_exit_mlx(env);
		}
		if (*line == ' ')
			previous_is_space = 1;
		else if (previous_is_space)
		{
			nb_of_elements++;
			previous_is_space = 0;
		}
		// if (*line != ' ')
		// 	previous_is_space = 1;
		// else if (previous_is_space && *line != ' ')
		// {
		// 	nb_of_elements++;
		// 	previous_is_space = 0;
		// }
		line++;
	}
	return (nb_of_elements);
}

void ft_get_grid_values(t_env *env)
{
	int fd_file;
	int	x;
	int	y;
	char **splitted_line;

	fd_file = open(env->file_name, O_RDONLY);
	if (fd_file == -1)
		ft_exit_mlx(env);

	y = 0;
	while (y < env->grid_height)
	{
		env->read_line = get_next_line(fd_file);
		splitted_line = ft_split(env->read_line, ' ');
		if (!splitted_line)
			ft_exit_mlx(env);
		x = 0;
		while (x < env->grid_width)
		{
			env->grid[x][y].x_grid = (x - env->grid_width / 2) * XY_SCALE_FACTOR;
			env->grid[x][y].y_grid = (y - env->grid_height / 2) * XY_SCALE_FACTOR;
			env->grid[x][y].z_grid = ft_atoi(splitted_line[x]) * Z_SCALE_FACTOR;
			printf("pt %d %d : %d %d %d\n", x, y, env->grid[x][y].x_grid, env->grid[x][y].y_grid, env->grid[x][y].z_grid);
			x++;
		}
		y++;

	}
		ft_print_env(env);
}

