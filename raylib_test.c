#include "raylib_test.h"

char	g_map[] = {
	'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
	'1','0','1','0','0','0','1','0','0','0','0','0','0','1',
	'1','0','1','0','0','0','1','0','1','1','0','0','0','1',
	'1','0','1','1','0','0','1','0','1','1','0','0','0','1',
	'1','0','0','1','0','0','0','0','1','1','1','0','0','1',
	'1','0','0','1','0','1','0','0','0','0','1','0','0','1',
	'1','0','0','0','0','1','0','0','0','0','1','0','0','1',
	'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
};

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

void	ft_init(t_raycast *data)
{
	data->map_size_x = 14;
	data->map_size_y = 8;

	data->map = g_map;

	data->screenWidth = data->map_size_x * TILE_SIZE;
	data->screenHeight = data->map_size_y * TILE_SIZE;

	data->player_angle = PI;

	data->player_delta.x = cos(data->player_angle) * PLAYER_STEP;
	data->player_delta.y = sin(data->player_angle) * PLAYER_STEP;

	data->player_position.x = (float)TILE_SIZE + TILE_SIZE/2;
	data->player_position.y = (float)TILE_SIZE + TILE_SIZE/2;

	InitWindow(data->screenWidth, data->screenHeight, "raylib_test");

	SetTargetFPS(60);
}

void	ft_player_movement(t_raycast *data)
{
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		data->player_angle += PLAYER_TURN;
		if (data->player_angle > 2 * PI)
			data->player_angle -= 2 * PI;
		data->player_delta.x = cos(data->player_angle) * PLAYER_STEP;
		data->player_delta.y = sin(data->player_angle) * PLAYER_STEP;
	}
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		data->player_angle -= PLAYER_TURN;
		if (data->player_angle < 0)
			data->player_angle += 2 * PI;
		data->player_delta.x = cos(data->player_angle) * PLAYER_STEP;
		data->player_delta.y = sin(data->player_angle) * PLAYER_STEP;
	}
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
	{
		data->player_position.x += data->player_delta.x;
		data->player_position.y += data->player_delta.y;
	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{
		data->player_position.x -= data->player_delta.x;
		data->player_position.y -= data->player_delta.y;
	}
}

void	ft_draw_frame(t_raycast *data)
{
	BeginDrawing();

		ClearBackground(BLACK);

		ft_draw_map(data->map, data->map_size_x, data->map_size_y);

		DrawText(TextFormat("Position - x: %.4f - y: %.4f", data->player_position.x, data->player_position.y), 10, 10, 20, DARKGRAY);
		DrawText(TextFormat("Delta - x: %.4f - y: %.4f", data->player_delta.x, data->player_delta.y), 10, 30, 20, DARKGRAY);
		DrawText(TextFormat("Angle: %.4f", data->player_angle), 10, 50, 20, DARKGRAY);
		// DrawText(TextFormat("FPS: %d", GetFPS()), 10, 30, 20, DARKGRAY);
		DrawFPS(data->screenWidth - 100, 10);

		DrawCircleV(data->player_position, 10, MAROON);
		Vector2 end;
		end.x = data->player_position.x + data->player_delta.x * 100;
		end.y = data->player_position.y + data->player_delta.y * 100;
		DrawLineV(data->player_position, end, BLACK);

	EndDrawing();
}

int main(void)
{
	t_raycast	data;

	ft_init(&data);
	
	while (!WindowShouldClose())
	{
		ft_player_movement(&data);

		ft_draw_frame(&data);
	}
	CloseWindow();

	return 0;
}