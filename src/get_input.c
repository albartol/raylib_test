#include "../include/raylib_test.h"

void	ft_player_movement(t_data *data)
{
	if (IsKeyDown(KEY_E) || IsKeyDown(KEY_RIGHT))
	{
		data->player_angle += PLAYER_TURN;
		if (data->player_angle > RADIAN)
			data->player_angle -= RADIAN;
		data->player_delta.x = cos(data->player_angle) * PLAYER_STEP;
		data->player_delta.y = sin(data->player_angle) * PLAYER_STEP;
	}
	if (IsKeyDown(KEY_Q) || IsKeyDown(KEY_LEFT))
	{
		data->player_angle -= PLAYER_TURN;
		if (data->player_angle < 0)
			data->player_angle += RADIAN;
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
	if (IsKeyDown(KEY_D))
	{
		data->player_side_angle = data->player_angle + PI_HALF;
		if (data->player_side_angle > RADIAN)
			data->player_side_angle -= RADIAN;
		data->player_position.x += cos(data->player_side_angle) * PLAYER_STEP;
		data->player_position.y += sin(data->player_side_angle) * PLAYER_STEP;
	}
	if (IsKeyDown(KEY_A))
	{
		data->player_side_angle = data->player_angle - PI_HALF;
		if (data->player_side_angle < 0)
			data->player_side_angle += RADIAN;
		data->player_position.x += cos(data->player_side_angle) * PLAYER_STEP;
		data->player_position.y += sin(data->player_side_angle) * PLAYER_STEP;
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
	ft_check_input(data);
	ft_player_movement(data);
}