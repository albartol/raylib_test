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

void	ft_init(t_data *data)
{
	data->map_size_x = 14;
	data->map_size_y = 8;

	data->map = g_map;

	data->screenWidth = data->map_size_x * TILE_SIZE;
	data->screenHeight = data->map_size_y * TILE_SIZE;

	data->player_angle = PI_HALF;

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