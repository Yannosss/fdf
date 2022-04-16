/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:56:05 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/16 12:56:39 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of parameters : 1 is expected\n", 2);
		exit(0);
	}
	ft_init_env(&env);
	ft_parse_input(&env, argv);
	ft_convert_grid_coordinates(&env);
	ft_init_mlx(&env);
	ft_draw_grid(&env);
	ft_event_manager(&env);
	mlx_loop(env.mlx);
	ft_exit_mlx(&env, NULL);
	return (0);
}
