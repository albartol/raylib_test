#include "../include/raylib_test.h"

void	ft_draw_frame(t_data *data)
{
	BeginDrawing();

		ClearBackground(RAYWHITE);

		if (data->show_map)
			ft_show_map(data);
		if (data->show_exit)
			ft_show_exit(data);
		if (data->show_stats)
			ft_show_stats(data);
		if (data->show_controls)
			ft_show_controls(data);	
		
		ft_raycast(data);

	EndDrawing();
}