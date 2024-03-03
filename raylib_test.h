
#ifndef RAYLIB_TEST_H
# define RAYLIB_TEST_H

# include <stddef.h>
# include <raylib.h>
# include <raymath.h>
# include <rlgl.h>
# include <stdlib.h>
# include <math.h>

# define TILE_SIZE 64
# define PLAYER_STEP 2.5
# define PLAYER_TURN 0.05

typedef struct	s_raycast
{
	char	*map;
	int		map_size_x;
	int		map_size_y;
	Vector2	player_position;
	Vector2	player_delta;
	float	player_angle;
	int		screenWidth;
	int		screenHeight;
}				t_raycast;


void	ft_draw_map(char *map, int map_size_x, int map_size_y);
void	ft_init(t_raycast *data);
void	ft_player_movement(t_raycast *data);
void	ft_draw_frame(t_raycast *data);

#endif