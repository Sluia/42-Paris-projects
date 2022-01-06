#include "so_long.h"

void	init_st(t_data *mlx)
{
	init_mlx_null(mlx);
	mlx->map.map = NULL;
	mlx->map.nb_lines = 0;
	mlx->map.line_length = 0;
	mlx->map.nb_start = 0;
	mlx->map.nb_exit = 0;
	mlx->map.nb_collectibles = 0;
	mlx->map.player_x = 0;
	mlx->map.player_y = 0;
	mlx->map.player_movement = 0;
}

void	init_mlx_null(t_data *mlx)
{
	int	i;

	mlx->mlx = NULL;
	mlx->window = NULL;
	mlx->img.img = NULL;
	i = 0;
	while (i < 5)
	{
		mlx->textures[i].img = NULL;
		i++;
	}
}

void	init_game(t_data *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		call_error("-> MLX initialization failed", mlx, -1);
	mlx->window_width = TEXTURE_RES * mlx->map.line_length;
	mlx->window_height = TEXTURE_RES * mlx->map.nb_lines;
	mlx->window = mlx_new_window(mlx->mlx, mlx->window_width,
			mlx->window_height, "so_long");
	if (mlx->window == NULL)
		call_error("-> MLX window error", mlx, -1);
	load_textures(mlx, TEXTURE_RES);
}

void	load_textures(t_data *mlx, int texture_res)
{
	char	*tex_path;
	int		i;

	tex_path = malloc(sizeof(char) * 19);
	if (tex_path == NULL)
		call_error("-> malloc() didn't work properly", mlx, -1);
	tex_path = ft_strcpy(tex_path, "textures/tex00.xpm", 18);
	tex_path[18] = '\0';
	i = 0;
	while (i < 5)
	{
		mlx->textures[i].img = mlx_xpm_file_to_image(mlx->mlx, tex_path,
				&texture_res, &texture_res);
		if (mlx->textures[i].img == NULL)
		{
			free(tex_path);
			call_error("-> MLX image error", mlx, -1);
		}
		mlx->textures[i].address = mlx_get_data_addr(mlx->textures[i].img,
				&mlx->textures[i].bits_per_pixel, &mlx->textures[i].line_length,
				&mlx->textures[i].endian);
		tex_path[13]++;
		i++;
	}
	free(tex_path);
}
