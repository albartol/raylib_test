#include "../include/raylib_test.h"

void	ft_draw_map(char *map, int map_size_x, int map_size_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_size_y)
	{
		x = 0;
		while(x < map_size_x)
		{
			if (map[y * map_size_x + x] == '1')
				DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, RED);
			else
				DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, RAYWHITE);

			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_data *data)
{
	Vector2 end;

	end.x = data->player_position.x + data->player_delta.x * 10;
	end.y = data->player_position.y + data->player_delta.y * 10;
	DrawLineV(data->player_position, end, BLACK);
	DrawCircleV(data->player_position, 10, BLACK);
}

void	ft_draw_frame(t_data *data)
{
	BeginDrawing();

		ClearBackground(BLACK);

		ft_draw_map(data->map, data->map_size_x, data->map_size_y);

		ft_draw_player(data);

		if (data->show_exit)
			ft_show_exit(data);
		if (data->show_stats)
			ft_show_stats(data);
		if (data->show_controls)
			ft_show_controls(data);

	EndDrawing();
}