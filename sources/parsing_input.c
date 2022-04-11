#include "fdf.h"

void ft_parse_input(t_env *env, char **argv)
{
	int fd_grid;

	fd_grid = open(argv[1], O_RDONLY);
	if (fd_grid == -1)
		ft_exit_mlx(env);
	ft_get_grid_size(env, argv, fd_grid);

}


void	ft_get_grid_size(t_env *env, char **argv, int fd)
{
	char	read_line;

	while (get_next_line(fd))
	{
		/* code */
	}

}