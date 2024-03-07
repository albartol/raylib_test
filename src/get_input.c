#include "../include/raylib_test.h"

static void	ft_player_movement(t_data *data)
{
	if (IsKeyDown(KEY_E) || IsKeyDown(KEY_RIGHT))
	{
		data->player.angle += PLAYER_TURN;
		if (data->player.angle > RADIAN)
			data->player.angle -= RADIAN;
		data->player.delta.x = cos(data->player.angle) * PLAYER_STEP;
		data->player.delta.y = sin(data->player.angle) * PLAYER_STEP;
	}
	if (IsKeyDown(KEY_Q) || IsKeyDown(KEY_LEFT))
	{
		data->player.angle -= PLAYER_TURN;
		if (data->player.angle < 0)
			data->player.angle += RADIAN;
		data->player.delta.x = cos(data->player.angle) * PLAYER_STEP;
		data->player.delta.y = sin(data->player.angle) * PLAYER_STEP;
	}
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
	{
		data->player.position.x += data->player.delta.x;
		data->player.position.y += data->player.delta.y;
	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{
		data->player.position.x -= data->player.delta.x;
		data->player.position.y -= data->player.delta.y;
	}
	if (IsKeyDown(KEY_D))
	{
		data->player.side_angle = data->player.angle + PI_HALF;
		if (data->player.side_angle > RADIAN)
			data->player.side_angle -= RADIAN;
		data->player.position.x += cos(data->player.side_angle) * PLAYER_STEP;
		data->player.position.y += sin(data->player.side_angle) * PLAYER_STEP;
	}
	if (IsKeyDown(KEY_A))
	{
		data->player.side_angle = data->player.angle - PI_HALF;
		if (data->player.side_angle < 0)
			data->player.side_angle += RADIAN;
		data->player.position.x += cos(data->player.side_angle) * PLAYER_STEP;
		data->player.position.y += sin(data->player.side_angle) * PLAYER_STEP;
	}
}

static void	ft_check_input(t_data *data, int key)
{
	if (key == KEY_F1)
	{
		if (data->show_stats)
			data->show_stats = 0;
		else
			data->show_stats = 1;
	}
	if (key == KEY_M)
	{
		if (data->show_map)
			data->show_map = 0;
		else
			data->show_map = 1;
	}
	if (key == KEY_ESCAPE)
	{
		if (!data->show_exit)
		{
			data->show_exit = 1;
			SetExitKey(KEY_ESCAPE);
		}
	}
	if (key == KEY_TAB)
	{
		if (data->show_exit)
		{
			SetExitKey(KEY_NULL);
			data->show_exit = 0;
		}
	}
	if (data->show_controls)
	{
		if (key == KEY_SPACE)
			data->show_controls = 0;
	}
}

void	ft_get_input(t_data *data)
{
	ft_check_input(data, GetKeyPressed());
	ft_player_movement(data);
}