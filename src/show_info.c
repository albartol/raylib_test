#include "../include/raylib_test.h"

void	ft_show_stats(t_data *data)
{
	DrawText(TextFormat("Position - x: %.4f - y: %.4f", data->player_position.x, data->player_position.y), 10, 10, 20, BLACK);
	DrawText(TextFormat("Delta - x: %.4f - y: %.4f", data->player_delta.x, data->player_delta.y), 10, 30, 20, BLACK);
	DrawText(TextFormat("Angle: %.2fº", data->player_angle * RAD2DEG), 10, 50, 20, BLACK);
	DrawText(TextFormat("FPS: %d", GetFPS()), data->screenWidth - 100, 10, 20, BLACK);
	// DrawFPS(data->screenWidth - 100, 10);
}

void	ft_show_exit(t_data *data)
{
	DrawText(TextFormat("Press ESC to exit or TAB to cancel"), 10, data->screenHeight - 30, 20, BLACK);
}

void	ft_show_controls(t_data *data)
{
	DrawText(TextFormat("W / UP and S / DOWN to move foreward and back"), TILE_SIZE + 3, data->screenHeight / 2 - 40, 20, BLACK);
	DrawText(TextFormat("Q / LEFT and E / RIGTH to rotate"), TILE_SIZE + 3, data->screenHeight / 2 - 20, 20, BLACK);
	DrawText(TextFormat("A and D to move sideways"), TILE_SIZE + 3, data->screenHeight / 2, 20, BLACK);
	DrawText(TextFormat("F1 to show stats"), TILE_SIZE + 3, data->screenHeight / 2 + 20, 20, BLACK);
	DrawText(TextFormat("ESC x 2 to exit"), TILE_SIZE + 3, data->screenHeight / 2 + 40, 20, BLACK);
	DrawText(TextFormat("Press SPACE BAR to close"), TILE_SIZE + 3, data->screenHeight / 2 + 60, 20, BLACK);
}