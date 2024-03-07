
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

# define TEXT_SIZE 20
# define TILE_SIZE 64
# define BIT_SIFT 6 /* 64 */
# define PLAYER_SIZE 10
# define PLAYER_STEP 2.5f
# define PLAYER_TURN 0.075f
# define RADIAN (PI * 2.0f)
# define PI_HALF (PI / 2.0f)
# define QUADRANT_3 (3 * PI_HALF)
# define ONE_DEG (1.0f * DEG2RAD)

typedef struct	s_ray
{
	Vector2	position;
	Vector2	offset;
	float	angle;
}				t_ray;

typedef struct	s_raycast
{
	t_ray	ray;
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
	int		screenWidth;
	int		screenHeight;
	short	show_stats;
	short	show_exit;
	short	show_controls;
	short	show_map;
	t_player	player;
}				t_data;

void	ft_get_input(t_data *data);

void	ft_draw_frame(t_data *data);

void    ft_show_map(t_data *data);
void	ft_show_exit(t_data *data);
void	ft_show_stats(t_data *data);
void	ft_show_controls(t_data *data);

void    ft_raycast(t_data *data);

#endif