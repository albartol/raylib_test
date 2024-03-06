#include "../include/raylib_test.h"

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

void	ft_draw_player(t_data *data)
{
	Vector2 end;

	end.x = data->player_position.x + data->player_delta.x * 10;
	end.y = data->player_position.y + data->player_delta.y * 10;
	DrawCircleV(data->player_position, 10, BLACK);
	DrawLineV(data->player_position, end, BLACK);
}

void	ft_init(t_data *data)
{
	data->map_size_x = 14;
	data->map_size_y = 8;

	data->map = g_map;

	data->screenWidth = data->map_size_x * TILE_SIZE;
	data->screenHeight = data->map_size_y * TILE_SIZE;

	data->player_angle = PI / 2;

	data->player_delta.x = cos(data->player_angle) * PLAYER_STEP;
	data->player_delta.y = sin(data->player_angle) * PLAYER_STEP;

	data->player_position.x = (float)TILE_SIZE + TILE_SIZE/2;
	data->player_position.y = (float)TILE_SIZE + TILE_SIZE/2;

	data->show_stats = 0;
	data->show_exit = 0;
	data->show_controls = 1;

	InitWindow(data->screenWidth, data->screenHeight, "raylib_test");

	SetTargetFPS(60);
	SetExitKey(KEY_NULL);
}

void	ft_player_movement(t_data *data)
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

void	ft_check_input(t_data *data)
{
	if (IsKeyPressed(KEY_F1))
	{
		if (data->show_stats)
			data->show_stats = 0;
		else
			data->show_stats = 1;
	}
	if (IsKeyPressed(KEY_ESCAPE))
	{
		if (!data->show_exit)
		{
			data->show_exit = 1;
			SetExitKey(KEY_ESCAPE);
		}
	}
	if (IsKeyPressed(KEY_TAB))
	{
		if (data->show_exit)
		{
			SetExitKey(KEY_NULL);
			data->show_exit = 0;
		}
	}
	if (data->show_controls)
	{
		if (IsKeyPressed(KEY_SPACE))
			data->show_controls = 0;
	}
}

void	ft_get_input(t_data *data)
{
	ft_player_movement(data);
	ft_check_input(data);
}

void	ft_show_stats(t_data *data)
{
	DrawText(TextFormat("Position - x: %.4f - y: %.4f", data->player_position.x, data->player_position.y), 10, 10, 20, BLACK);
	DrawText(TextFormat("Delta - x: %.4f - y: %.4f", data->player_delta.x, data->player_delta.y), 10, 30, 20, BLACK);
	DrawText(TextFormat("Angle: %.2fº", data->player_angle * (180 / PI)), 10, 50, 20, BLACK);
	DrawText(TextFormat("FPS: %d", GetFPS()), data->screenWidth - 100, 10, 20, BLACK);
	// DrawFPS(data->screenWidth - 100, 10);
}

void	ft_show_exit(t_data *data)
{
	DrawText(TextFormat("Press ESC to exit or TAB to cancel"), 10, data->screenHeight - 30, 20, BLACK);
}

void	ft_show_controls(t_data *data)
{
	DrawText(TextFormat("W / UP to move foreward"), TILE_SIZE + 3, data->screenHeight / 2 - 40, 20, BLACK);
	DrawText(TextFormat("S / DOWN to move back"), TILE_SIZE + 3, data->screenHeight / 2 - 20, 20, BLACK);
	DrawText(TextFormat("A / LEFT and D / RIGTH to rotate"), TILE_SIZE + 3, data->screenHeight / 2, 20, BLACK);
	DrawText(TextFormat("F1 to show stats"), TILE_SIZE + 3, data->screenHeight / 2 + 20, 20, BLACK);
	DrawText(TextFormat("ESC x 2 to exit"), TILE_SIZE + 3, data->screenHeight / 2 + 40, 20, BLACK);
	DrawText(TextFormat("Press SPACE BAR to close"), TILE_SIZE + 3, data->screenHeight / 2 + 60, 20, BLACK);
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

int main(void)
{
	t_data	data;

	ft_init(&data);
	
	while (!WindowShouldClose())
	{
		ft_get_input(&data);

		ft_draw_frame(&data);
	}
	CloseWindow();

	return 0;
}