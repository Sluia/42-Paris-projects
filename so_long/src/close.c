#include "so_long.h"

int	close_game(t_data *mlx)
{
	free_mlx(mlx);
	free_map(&mlx->map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->map != NULL)
	{
		i = 0;
		while (i < map->nb_lines)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	free_mlx(t_data *mlx)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mlx->textures[i].img != NULL)
			mlx_destroy_image(mlx->mlx, mlx->textures[i].img);
		i++;
	}
	if (mlx->img.img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx != NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}
