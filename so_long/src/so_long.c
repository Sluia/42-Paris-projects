#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	mlx;

	init_st(&mlx);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) >= 4)
		{
			if (ft_strcmp(".ber", &argv[1][ft_strlen(argv[1]) - 4], 4) == 0)
			{
				parse_map(argv[1], &mlx);
				launch_game(&mlx);
			}
		}
	}
	call_error("-> invalid argument", &mlx, -1);
	return (0);
}

void	parse_map(char *ber_file, t_data *mlx)
{
	get_map_lines(ber_file, mlx);
	is_map_rect(ber_file, mlx);
	copy_map_array(ber_file, mlx);
	check_char(mlx);
}

void	launch_game(t_data *mlx)
{
	init_game(mlx);
	mlx_hook(mlx->window, 2, 1L << 0, get_keys, mlx);
	mlx_hook(mlx->window, 33, 1L << 2, close_game, mlx);
	mlx_loop_hook(mlx->mlx, play, mlx);
	mlx_loop(mlx->mlx);
}
