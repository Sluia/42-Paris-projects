#include "so_long.h"

void	prep_draw(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map.nb_lines)
	{
		j = 0;
		while (j < mlx->map.line_length)
		{
			if (search_char("0CE", mlx->map.map[i][j]) == 1)
				draw(mlx, 0, j * TEXTURE_RES, i * TEXTURE_RES);
			if (mlx->map.map[i][j] == '1')
				draw(mlx, 1, j * TEXTURE_RES, i * TEXTURE_RES);
			if (mlx->map.map[i][j] == 'C')
				draw(mlx, 2, j * TEXTURE_RES, i * TEXTURE_RES);
			if (mlx->map.map[i][j] == 'E')
				draw(mlx, 3, j * TEXTURE_RES, i * TEXTURE_RES);
			j++;
		}
		i++;
	}
	draw(mlx, 4, mlx->map.player_x * TEXTURE_RES, mlx->map.player_y
		* TEXTURE_RES);
}

void	draw(t_data *mlx, int tex_index, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < TEXTURE_RES)
	{
		j = 0;
		while (j < TEXTURE_RES)
		{
			my_mlx_pixel_put(&mlx->img, x + j, y + i,
				get_pixel_color(&mlx->textures[tex_index], j, i));
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (color >= 0)
	{
		dst = img->address + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*color;

	color = img->address + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	return (*(int *)color);
}
