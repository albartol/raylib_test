#include "../include/raylib_test.h"

char	g_map[] = {
	'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
	'1','0','1','0','0','0','1','0','0','0','0','0','0','1',
	'1','0','1','0','0','0','1','0','1','1','0','0','0','1',
	'1','0','1','1','0','0','0','0','1','1','0','0','0','1',
	'1','0','0','1','0','0','0','0','1','1','1','0','0','1',
	'1','0','0','1','0','1','0','0','0','0','1','0','0','1',
	'1','0','0','0','0','1','0','0','0','0','1','0','0','1',
	'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
};

static void	ft_init(t_data *data)
{
	data->map_size_x = 14;
	data->map_size_y = 8;

	data->map = g_map;

	data->screenWidth = data->map_size_x << BIT_SIFT;
	data->screenHeight = data->map_size_y << BIT_SIFT;

	data->player.angle = PI_HALF;

	data->player.delta.x = cos(data->player.angle) * PLAYER_STEP;
	data->player.delta.y = sin(data->player.angle) * PLAYER_STEP;

	data->player.position.x = (float)(data->screenWidth >> 1);
	data->player.position.y = (float)(data->screenHeight >> 1);

	data->show_map = 0;
	data->show_exit = 0;
	data->show_stats = 0;
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

	return (EXIT_SUCCESS);
}