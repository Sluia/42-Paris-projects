#include "so_long.h"

void	check_char(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map.nb_lines)
	{
		j = 0;
		while (j < mlx->map.line_length)
		{
			check_char2(mlx, i, j);
			j++;
		}
		i++;
	}
	if (mlx->map.nb_start != 1 || mlx->map.nb_exit != 1
		|| mlx->map.nb_collectibles == 0 || check_walls(mlx->map) == 0)
		call_error("-> invalid map", mlx, -1);
}

void	check_char2(t_data *mlx, int i, int j)
{
	if (search_char("01CEP", mlx->map.map[i][j]) == 0)
		call_error("-> invalid map", mlx, -1);
	if (mlx->map.map[i][j] == 'C')
		mlx->map.nb_collectibles++;
	if (mlx->map.map[i][j] == 'E')
		mlx->map.nb_exit++;
	if (mlx->map.map[i][j] == 'P')
	{
		mlx->map.nb_start++;
		mlx->map.map[i][j] = '0';
		mlx->map.player_x = j;
		mlx->map.player_y = i;
	}
}

int	check_walls(t_map map)
{
	int	i;

	i = 0;
	while (i < map.line_length)
	{
		if (map.map[0][i] != '1' && map.map[map.nb_lines - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map.nb_lines)
	{
		if (map.map[i][0] != '1' && map.map[i][map.line_length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
