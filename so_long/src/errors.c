#include "so_long.h"

void	call_error(char *error_msg, t_data *mlx, int fd)
{
	char	*join_msg;

	free_mlx(mlx);
	if (fd != -1)
		close(fd);
	free_map(&mlx->map);
	join_msg = ft_strjoin_error("Error:\n", error_msg);
	write_str_nl(join_msg);
	free(join_msg);
	exit(EXIT_FAILURE);
}
