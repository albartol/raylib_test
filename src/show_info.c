#include "../include/raylib_test.h"

void	ft_show_stats(t_data *data)
{
	DrawText(TextFormat("Position - x: %.4f - y: %.4f", data->player.position.x, data->player.position.y), 10, 5, TEXT_SIZE, BLACK);
	DrawText(TextFormat("Delta - x: %.4f - y: %.4f", data->player.delta.x, data->player.delta.y), 10, 25, TEXT_SIZE, BLACK);
	DrawText(TextFormat("Angle: %.2fº", data->player.angle * RAD2DEG), 10, 45, TEXT_SIZE, BLACK);
	DrawText(TextFormat("FPS: %d", GetFPS()), SCREEN_WIDTH - 100, 5, TEXT_SIZE, BLACK);
	// DrawFPS(SCREEN_WIDTH - 100, 10);
}

void	ft_show_exit(void)
{
	DrawText(TextFormat("Press ESC to exit or TAB to cancel"), 10, SCREEN_HEIGHT - 30, TEXT_SIZE, BLACK);
}

void	ft_show_controls(void)
{
	int	x;
	int	y;

	x = SCREEN_WIDTH >> 3;
	y = SCREEN_HEIGHT >> 1;
	DrawText(TextFormat("W / UP and S / DOWN to move foreward and back"), x, y - 60, TEXT_SIZE, BLACK);
	DrawText(TextFormat("Q / LEFT and E / RIGTH to rotate"), x, y - 40, TEXT_SIZE, BLACK);
	DrawText(TextFormat("A and D to move sideways"), x, y - 20, TEXT_SIZE, BLACK);
	DrawText(TextFormat("F1 to show stats and M to open the map"), x, y, TEXT_SIZE, BLACK);
	DrawText(TextFormat("ESC x 2 to exit"), x, y + 20, TEXT_SIZE, BLACK);
	DrawText(TextFormat("Press SPACEBAR to close"), x, y + 60, TEXT_SIZE, BLACK);
}

void	ft_show_map(t_data *data)
{
	Vector2 end;
	int	y;
	int	x;

	y = 0;
	while (y < data->map_size_y)
	{
		x = 0;
		while(x < data->map_size_x)
		{
			if (data->map[y * data->map_size_x + x] == '1')
				DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, RED);
			else
				DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1, BLACK);

			x++;
		}
		y++;
	}
	end.x = data->player.position.x + data->player.delta.x * 10;
	end.y = data->player.position.y + data->player.delta.y * 10;
	DrawLineV(data->player.position, end, VIOLET);
	DrawCircleV(data->player.position, PLAYER_SIZE, VIOLET);
	ft_raycast(data);
}

void	ft_show_mini_map(t_data *data)
{
	Vector2 end;
	Vector2 org;
	int	y;
	int	x;

	y = 0;
	DrawRectangle(0, 0, (TILE_SIZE >> 2) * data->map_size_x - 1, (TILE_SIZE >> 2) * data->map_size_y - 1, RAYWHITE);
	while (y < data->map_size_y)
	{
		x = 0;
		while(x < data->map_size_x)
		{
			if (data->map[y * data->map_size_x + x] == '1')
				DrawRectangle(x * (TILE_SIZE >> 2), y * (TILE_SIZE >> 2), (TILE_SIZE >> 2) - 1, (TILE_SIZE >> 2) - 1, RED);
			else
				DrawRectangle(x * (TILE_SIZE >> 2), y * (TILE_SIZE >> 2), (TILE_SIZE >> 2) - 1, (TILE_SIZE >> 2) - 1, BLACK);

			x++;
		}
		y++;
	}
	org.x = data->player.position.x / 4;
	org.y = data->player.position.y / 4;
	end.x = org.x + data->player.delta.x * 10;
	end.y = org.y + data->player.delta.y * 10;
	DrawLineV(org, end, VIOLET);
	DrawCircleV(org, (PLAYER_SIZE >> 2), VIOLET);
}