#include "so_long.h"

void	move_left(t_map *map)
{
	if (map->map[map->player_y][map->player_x - 1] != '1')
	{
		map->player_x--;
		map->player_movement++;
		write_nb(map->player_movement);
		write_char('\n');
	}
}

void	move_right(t_map *map)
{
	if (map->map[map->player_y][map->player_x + 1] != '1')
	{
		map->player_x++;
		map->player_movement++;
		write_nb(map->player_movement);
		write_char('\n');
	}
}

void	move_up(t_map *map)
{
	if (map->map[map->player_y - 1][map->player_x] != '1')
	{
		map->player_y--;
		map->player_movement++;
		write_nb(map->player_movement);
		write_char('\n');
	}
}

void	move_down(t_map *map)
{
	if (map->map[map->player_y + 1][map->player_x] != '1')
	{
		map->player_y++;
		map->player_movement++;
		write_nb(map->player_movement);
		write_char('\n');
	}
}
