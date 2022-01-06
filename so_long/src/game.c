#include "so_long.h"

int	play(t_data *mlx)
{
	void	*old_img;

	check_player_pos(mlx);
	old_img = NULL;
	if (mlx->img.img != NULL)
		old_img = mlx->img.img;
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->window_width,
			mlx->window_height);
	if (mlx->img.img == NULL)
	{
		if (old_img != NULL)
			mlx_destroy_image(mlx->mlx, old_img);
		call_error("-> MLX image error", mlx, -1);
	}
	mlx->img.address = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	prep_draw(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
	if (old_img != NULL)
		mlx_destroy_image(mlx->mlx, old_img);
	return (0);
}

void	check_player_pos(t_data *mlx)
{
	if (mlx->map.map[mlx->map.player_y][mlx->map.player_x] == 'C')
		mlx->map.map[mlx->map.player_y][mlx->map.player_x] = '0';
	if (mlx->map.map[mlx->map.player_y][mlx->map.player_x] == 'E' &&
		check_collectibles(mlx->map) == 0)
		close_game(mlx);
}

int	check_collectibles(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.nb_lines)
	{
		j = 0;
		while (j < map.line_length)
		{
			if (map.map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_keys(int keycode, t_data *mlx)
{
	if (keycode == 113)
		move_left(&mlx->map);
	if (keycode == 100)
		move_right(&mlx->map);
	if (keycode == 122)
		move_up(&mlx->map);
	if (keycode == 115)
		move_down(&mlx->map);
	if (keycode == 65307)
		close_game(mlx);
	return (0);
}
