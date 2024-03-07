#include "../include/raylib_test.h"

char	g_map[] = {
	'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
	'1','0','1','0','0','0','1','0','0','0','0','0','0','1',
	'1','0','1','0','0','0','1','0','1','1','0','0','0','1',
	'1','0','1','1','0','0','0','0','1','1','0','0','0','1',
	'1','0','0','1','0','0','0','0','1','1','1','0','0','1',
	'1','0','0','1','0','0','0','0','0','0','1','0','0','1',
	'1','0','0','0','0','0','0','0','0','0','1','0','0','1',
	'1','0','1','0','0','0','0','0','0','0','0','0','0','1',
	'1','0','1','0','0','0','0','0','1','1','0','0','0','1',
	'1','0','1','1','0','0','0','0','1','1','0','0','0','1',
	'1','0','0','1','0','0','0','0','1','1','1','0','0','1',
	'1','0','0','1','0','1','0','0','0','0','1','0','0','1',
	'1','0','0','0','0','1','0','0','0','0','1','0','0','1',
	'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
};

static void	ft_init(t_data *data)
{
	data->map_size_x = 14;
	data->map_size_y = 14;

	data->map = g_map;

	data->map_width = data->map_size_x << BIT_SIFT;
	data->map_height = data->map_size_y << BIT_SIFT;

	data->player.angle = 0;

	data->player.delta.x = cos(data->player.angle) * PLAYER_STEP;
	data->player.delta.y = sin(data->player.angle) * PLAYER_STEP;

	data->player.position.x = (float)(data->map_width >> 1);
	data->player.position.y = (float)(data->map_height >> 1);

	data->show_map = 0;
	data->show_exit = 0;
	data->show_stats = 0;
	data->show_mini_map = 0;
	data->show_controls = 1;

	// InitWindow(data->map_width, data->map_height, "raylib_test");
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib_test");

	data->window_height = WINDOW_HEIGHT;
	data->window_width = WINDOW_WIDTH;
	// SetWindowSize(data->window_width, data->window_height);
	// ToggleBorderlessWindowed();

	SetTargetFPS(FPS);
	SetExitKey(KEY_NULL);
	// HideCursor();
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