#include "so_long.h"

void	get_map_lines(char *ber_file, t_data *mlx)
{
	int		fd;
	char	*line;
	int		gnl_result;

	gnl_result = 1;
	fd = open(ber_file, O_RDONLY);
	if (fd == -1)
		call_error("-> unable to open the map", mlx, -1);
	while (gnl_result == 1)
	{
		gnl_result = get_next_line(fd, &line);
		if (gnl_result == -1)
			call_error("-> GNL error", mlx, fd);
		if (ft_strlen(line))
			mlx->map.nb_lines++;
		free(line);
	}
	close(fd);
	if (mlx->map.nb_lines < 2)
		call_error("-> invalid map", mlx, -1);
}

void	is_map_rect(char *ber_file, t_data *mlx)
{
	int		fd;
	char	*line;
	int		gnl_result;
	int		i;

	fd = open(ber_file, O_RDONLY);
	if (fd == -1)
		call_error("-> unable to open the map", mlx, -1);
	i = 0;
	while (i < mlx->map.nb_lines)
	{
		gnl_result = get_next_line(fd, &line);
		if (gnl_result == -1)
			call_error("-> GNL error", mlx, fd);
		gnl_result = ft_strlen(line);
		free(line);
		if (gnl_result < 3)
			call_error("-> invalid map", mlx, fd);
		if (mlx->map.line_length == 0)
			mlx->map.line_length = gnl_result;
		if (mlx->map.line_length != gnl_result)
			call_error("-> invalid map", mlx, fd);
		i++;
	}
	close(fd);
}

void	copy_map_array(char *ber_file, t_data *mlx)
{
	int	fd;

	fd = open(ber_file, O_RDONLY);
	if (fd == -1)
		call_error("-> unable to open the map", mlx, -1);
	mlx->map.map = ft_calloc(mlx->map.nb_lines, sizeof(char *));
	if (mlx->map.map == NULL)
		call_error("-> malloc() didn't work properly", mlx, fd);
	copy_map_array2(mlx, fd);
	close(fd);
}

void	copy_map_array2(t_data *mlx, int fd)
{
	char	*line;
	int		gnl_result;
	int		i;

	i = 0;
	while (i < mlx->map.nb_lines)
	{
		gnl_result = get_next_line(fd, &line);
		if (gnl_result == -1)
			call_error("-> GNL error", mlx, fd);
		mlx->map.map[i] = ft_calloc(mlx->map.line_length, sizeof(char));
		if (mlx->map.map[i] == NULL)
		{
			free(line);
			call_error("-> malloc() didn't work properly", mlx, fd);
		}
		ft_strcpy(mlx->map.map[i], line, mlx->map.line_length);
		free(line);
		i++;
	}
}
