
#ifndef RAYLIB_TEST_H
# define RAYLIB_TEST_H

# include <stddef.h>
# include <raylib.h>
# include <raymath.h>
# include <rlgl.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include <stdio.h>

// # define SCREEN_WIDTH 640
// # define SCREEN_HEIGHT 480
// # define TEXT_SIZE 20
// # define TILE_SIZE 64
// # define BIT_SIFT 6 /* 64 */
// # define PLAYER_SIZE 10
# define PLAYER_STEP 2.5f
# define PLAYER_TURN 0.075f
# define RADIAN (PI * 2.0f)
# define PI_HALF (PI / 2.0f)
# define QUADRANT_3 (3.0f * PI_HALF)
# define ONE_DEG (1.0f * DEG2RAD)
// # define RAY_NUM 180
// # define RAY_WIDTH 4
// # define RAY_BIT 2
# define ANGLE_PER_RAY (ONE_DEG / 2)

typedef enum e_config_data
{
	FPS = 60,
	WINDOW_WIDTH = 720,
	WINDOW_HEIGHT = 450,
	TEXT_SIZE = 20,
	TILE_SIZE = 64,
	BIT_SIFT = 6,
	PLAYER_SIZE = 10,
	RAY_NUM = 180,
	RAY_WIDTH = 4,
	RAY_BIT = 2
}			t_config_data;

typedef struct	s_ray
{
	Vector2	position;
	Vector2	offset;
	float	angle;
}				t_ray;

typedef struct	s_raycast
{
	t_ray	ray;
	Color	ray_color;
	int		ray_num;
	int		depth_of_ray;
	float	neg_tan;
	float	inverse_neg_tan;
	int		map_pos_x;
	int		map_pos_y;
	int		map_pos;
	Vector2	hor_col;
	Vector2	ver_col;
	Vector2	col_dist;
	float	dist;
	float	wall_height;
	float	wall_offset;
	float	fisheye_angle;
}				t_raycast;

typedef struct	s_player
{
	Vector2	position;
	Vector2	delta;
	float	angle;
	float	side_angle;
}				t_player;

typedef struct	s_data
{
	char	*map;
	int		map_size_x;
	int		map_size_y;
	int		map_width;
	int		map_height;
	int		window_width;
	int		window_height;
	short	show_stats;
	short	show_exit;
	short	show_controls;
	short	show_map;
	short	show_mini_map;
	t_player	player;
}				t_data;

void	ft_get_input(t_data *data);

void	ft_draw_frame(t_data *data);

void    ft_show_map(t_data *data);
void	ft_show_mini_map(t_data *data);
void	ft_show_exit(t_data *data);
void	ft_show_stats(t_data *data);
void	ft_show_controls(t_data *data);

void    ft_raycast(t_data *data);

#endif