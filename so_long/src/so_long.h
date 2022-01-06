#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"

# define BUFFER_SIZE 100
# define TEXTURE_RES 32

typedef struct s_map
{
	char	**map;
	int		nb_lines;
	int		line_length;
	int		nb_start;
	int		nb_exit;
	int		nb_collectibles;
	int		player_x;
	int		player_y;
	int		player_movement;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	t_img	img;
	t_img	textures[5];
	int		window_width;
	int		window_height;
	t_map	map;
}	t_data;

void	parse_map(char *ber_file, t_data *mlx);
void	launch_game(t_data *mlx);

void	call_error(char *error_msg, t_data *mlx, int fd);

void	init_st(t_data *mlx);
void	init_mlx_null(t_data *mlx);
void	init_game(t_data *mlx);
void	load_textures(t_data *mlx, int texture_res);

void	get_map_lines(char *ber_file, t_data *mlx);
void	is_map_rect(char *ber_file, t_data *mlx);
void	copy_map_array(char *ber_file, t_data *mlx);
void	copy_map_array2(t_data *mlx, int fd);

void	check_char(t_data *mlx);
void	check_char2(t_data *mlx, int i, int j);
int		check_walls(t_map map);

int		play(t_data *mlx);
void	check_player_pos(t_data *mlx);
int		check_collectibles(t_map map);
int		get_keys(int keycode, t_data *mlx);

void	prep_draw(t_data *mlx);
void	draw(t_data *mlx, int tex_index, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_pixel_color(t_img *img, int x, int y);

int		close_game(t_data *mlx);
void	free_map(t_map *map);
void	free_mlx(t_data *mlx);

void	move_left(t_map *map);
void	move_right(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);

void	clear_buf(char *buffer, int index);
int		chk_buf_read(char *buffer, int *p_buf_len, char **line);
int		to_return(char **line, int buf_len);
int		get_next_line(int fd, char **line);

int		ft_strlen(char *str);
int		cpy_buf(char *buffer, int index, int len);
int		nl_index(char *buffer, int len);
char	*ft_strdup(char *src, int len);
char	*ft_strjoin(char *line, char *str2, int len);

int		ft_strcmp(char *str1, char *str2, int n);
char	*ft_strcpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, char *src, int n);
char	*ft_strjoin_error(char *str1, char *str2);
int		search_char(char *str, int c);

void	write_char(char c);
void	write_str_nl(char *str);
void	write_nb(int nb);
void	*ft_calloc(int nb_elem, int size);
void	*ft_memset(void *ptr, int c, int n);

#endif
