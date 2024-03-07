#include "../include/raylib_test.h"

static float	ft_distace(Vector2 origin, Vector2 end)
{
	return (sqrt((end.x - origin.x) * (end.x - origin.x) + (end.y - origin.y) * (end.y - origin.y)));
}

static void	ft_horizontal_colision(t_data *data, t_raycast *raycast)
{
	raycast->depth_of_ray = 0;
	raycast->col_dist.x = FLT_MAX;
	if (raycast->ray.angle == 0 || raycast->ray.angle == PI)
	{
		raycast->ray.position.y = data->player.position.y;
		raycast->ray.position.x = data->player.position.x;
		raycast->depth_of_ray = data->map_size_y;
	}
	else if (raycast->ray.angle > PI) /* THIRD && FOURTH QUADRANTS */
	{
		// raycast->ray.position.y = (((int)data->player.position.y >> BIT_SIFT) << BIT_SIFT) - 0.00000763;
		raycast->ray.position.y = (((int)data->player.position.y >> BIT_SIFT) << BIT_SIFT) - 0.1;
		raycast->ray.position.x = (data->player.position.y - raycast->ray.position.y) * raycast->inverse_neg_tan + data->player.position.x;
		raycast->ray.offset.y = -TILE_SIZE;
		raycast->ray.offset.x = TILE_SIZE * raycast->inverse_neg_tan;
	}
	else if (raycast->ray.angle < PI) /* FIRST && SECOND QUADRANTS */
	{
		raycast->ray.position.y = (((int)data->player.position.y >> BIT_SIFT) << BIT_SIFT) + TILE_SIZE;
		raycast->ray.position.x = (data->player.position.y - raycast->ray.position.y) * raycast->inverse_neg_tan + data->player.position.x;
		raycast->ray.offset.y = TILE_SIZE;
		raycast->ray.offset.x = -TILE_SIZE * raycast->inverse_neg_tan;
	}
	while (raycast->depth_of_ray < data->map_size_y)
	{
		raycast->map_pos_y = (int)raycast->ray.position.y >> BIT_SIFT;
		raycast->map_pos_x = (int)raycast->ray.position.x >> BIT_SIFT;
		raycast->map_pos = raycast->map_pos_y * data->map_size_x + raycast->map_pos_x;
		if (raycast->map_pos > 0 && raycast->map_pos < data->map_size_x * data->map_size_y && data->map[raycast->map_pos] == '1')
		{
			raycast->hor_col.x = raycast->ray.position.x;
			raycast->hor_col.y = raycast->ray.position.y;
			raycast->col_dist.x = ft_distace(data->player.position, raycast->hor_col);
			raycast->depth_of_ray = data->map_size_y;
		}
		else
		{
			raycast->ray.position.y += raycast->ray.offset.y;
			raycast->ray.position.x += raycast->ray.offset.x;
			raycast->depth_of_ray++;
		}
	}
}

static void	ft_vertical_colision(t_data *data, t_raycast *raycast)
{
	raycast->depth_of_ray = 0;
	raycast->col_dist.y = FLT_MAX;
	if (raycast->ray.angle == PI_HALF || raycast->ray.angle == QUADRANT_3)
	{
		raycast->ray.position.x = data->player.position.x;
		raycast->ray.position.y = data->player.position.y;
		raycast->depth_of_ray = data->map_size_x;
	}
	else if (raycast->ray.angle > PI_HALF && raycast->ray.angle < QUADRANT_3) /* SECOND && THIRD QUADRANTS */
	{
		raycast->ray.position.x = (((int)data->player.position.x >> BIT_SIFT) << BIT_SIFT) - 0.0001;
		raycast->ray.position.y = (data->player.position.x - raycast->ray.position.x) * raycast->neg_tan + data->player.position.y;
		raycast->ray.offset.x = -TILE_SIZE;
		raycast->ray.offset.y = TILE_SIZE * raycast->neg_tan;
	}
	else if (raycast->ray.angle > QUADRANT_3 || raycast->ray.angle < PI_HALF) /* FIRST && FOURTH QUADRANTS */
	{
		raycast->ray.position.x = (((int)data->player.position.x >> BIT_SIFT) << BIT_SIFT) + TILE_SIZE;
		raycast->ray.position.y = (data->player.position.x - raycast->ray.position.x) * raycast->neg_tan + data->player.position.y;
		raycast->ray.offset.x = TILE_SIZE;
		raycast->ray.offset.y = -TILE_SIZE * raycast->neg_tan;
	}
	while (raycast->depth_of_ray < data->map_size_x)
	{
		raycast->map_pos_x = (int)raycast->ray.position.x >> BIT_SIFT;
		raycast->map_pos_y = (int)raycast->ray.position.y >> BIT_SIFT;
		raycast->map_pos = raycast->map_pos_y * data->map_size_x + raycast->map_pos_x;
		if (raycast->map_pos > 0 && raycast->map_pos < data->map_size_x * data->map_size_y && data->map[raycast->map_pos] == '1')
		{
			raycast->ver_col.x = raycast->ray.position.x;
			raycast->ver_col.y = raycast->ray.position.y;
			raycast->col_dist.y = ft_distace(data->player.position, raycast->ver_col);
			raycast->depth_of_ray = data->map_size_x;
		}
		else
		{
			raycast->ray.position.x += raycast->ray.offset.x;
			raycast->ray.position.y += raycast->ray.offset.y;
			raycast->depth_of_ray++;
		}
	}
}

void    ft_raycast(t_data *data)
{
	t_raycast	raycast;

	if (!data->show_map)
	{
		DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT >> 1, LIGHTGRAY);
		DrawRectangle(0, SCREEN_HEIGHT >> 1, SCREEN_WIDTH, SCREEN_HEIGHT >> 1, GRAY);
	}
	raycast.ray.angle = data->player.angle - (ONE_DEG * 45);
	if (raycast.ray.angle < 0)
		raycast.ray.angle += RADIAN;
	if (raycast.ray.angle > RADIAN)
		raycast.ray.angle -= RADIAN;
	raycast.ray.offset.y = 0;
	raycast.ray.offset.x = 0;
	raycast.ver_col.x = data->player.position.x;
	raycast.ver_col.y = data->player.position.y;
	raycast.hor_col.x = data->player.position.x;
	raycast.hor_col.y = data->player.position.y;
	raycast.ray.position.y = data->player.position.y;
	raycast.ray.position.x = data->player.position.x;
	raycast.ray_num = 0;
	while (raycast.ray_num < RAY_NUM)
	{
		raycast.ray_color = RED;
		raycast.neg_tan = -tan(raycast.ray.angle);
		raycast.inverse_neg_tan = 1 / raycast.neg_tan;
		ft_horizontal_colision(data, &raycast);
		ft_vertical_colision(data, &raycast);
		if (raycast.col_dist.y < raycast.col_dist.x)
		{
			raycast.ray.position.x = raycast.ver_col.x;
			raycast.ray.position.y = raycast.ver_col.y;
			raycast.dist = raycast.col_dist.y;
			if (data->show_map)
				DrawLineV(data->player.position, raycast.ray.position, ORANGE);
			raycast.ray_color = MAROON;
		}
		else
		{
			raycast.ray.position.x = raycast.hor_col.x;
			raycast.ray.position.y = raycast.hor_col.y;
			raycast.dist = raycast.col_dist.x;
			if (data->show_map)
				DrawLineV(data->player.position, raycast.ray.position, GREEN);
		}
		raycast.fisheye_angle = data->player.angle - raycast.ray.angle;
		if (raycast.fisheye_angle < 0)
			raycast.fisheye_angle += RADIAN;
		if (raycast.fisheye_angle > RADIAN)
			raycast.fisheye_angle -= RADIAN;
		raycast.dist *= cos(raycast.fisheye_angle);
		raycast.wall_height = (TILE_SIZE * SCREEN_HEIGHT) / raycast.dist;
		if (raycast.wall_height > SCREEN_HEIGHT)
			raycast.wall_height = SCREEN_HEIGHT;
		raycast.wall_offset = (SCREEN_HEIGHT >> 1) - raycast.wall_height / 2;
		if (!data->show_map)
			DrawRectangle(raycast.ray_num << RAY_BIT, raycast.wall_offset, RAY_WIDTH, raycast.wall_height, raycast.ray_color);
		raycast.ray_num++;
		raycast.ray.angle += ANGLE_PER_RAY;
		if (raycast.ray.angle < 0)
			raycast.ray.angle += RADIAN;
		if (raycast.ray.angle > RADIAN)
			raycast.ray.angle -= RADIAN;
	}
}