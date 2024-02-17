
#ifndef SLMM_H_
# define SLMM_H_

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define VERSION "0.2"

# define TRUE 1
# define FALSE 0

# define TILE_SIZE 16
# define SCALE 3
# define TS TILE_SIZE * SCALE

# define WALL_FILE "imgs/wall-01.png"
# define FLOOR_FILE "imgs/floor-01.png"
# define CURSOR_FILE "imgs/cursor-01.png"

# define RED		"\033[0;91m"
# define GREEN		"\033[0;92m"
# define YELLOW		"\033[0;93m"
# define BLUE		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN		"\033[0;96m"
# define RESET		"\033[0m"

// 1 WALL
// 0 FREE
// P PLAYER
// E EXIT
// M ENEMY
//   TILE_HIGHLIGHT
# define MAX_IMAGES 6

typedef enum e_error
{
	ERROR_ALLOCATE,
	ERROR_LOADING_IMAGE,
}	t_error;

typedef struct s_vec2
{
	int	x;
	int	y;
}		t_vec2;

typedef struct s_cell
{
	mlx_image_t	*img;
	mlx_image_t	*cimg;
	t_vec2		tpos;
	int			is_wall;
	char		c;
}	t_cell;

typedef struct s_map
{
	t_cell	**matrix;
	int		width;
	int		height;
}	t_map;

// AppData
typedef struct s_ad
{
	mlx_t		*mlx;
	char		*file;
	mlx_image_t	*images[MAX_IMAGES];
	mlx_image_t	*cimg;
	t_vec2		cpos;					// Cursor Pos
	t_vec2		ompos;					// Old Mouse Pos
	t_map		map;
	int			mpressed;
	char		lastc;					// Last Character
}				t_ad;

// Main
t_ad	*getad();
void	free_map_imgs(t_map *map);
void	free_map(t_map *map);
void	free_ad(t_ad *ad);
void	terminate(int error, t_ad *ad);

// Error
void	print_error(t_error error);

// Flags
void	check_flags(int ac, char **av);

// Init1
void	init_ad(void);
int		init_empty_map(t_map *map);
int		init_file(int ac, char **av, t_ad *ad);
int		init_mlx_window(t_ad *ad);
int		init_tiles(t_ad *ad);

// Loader1
int		load_and_set_map_dimensions(char *file, t_ad *ad);
int		load_map_from_file(char *file, t_ad *ad);
int		load_image(char *file, mlx_image_t **img, t_ad *ad);

// Hooks
void	slmm_key_hook(mlx_key_data_t keydata, void *param);
void	slmm_mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void* param);
// void	slmm_scroll_hook(double xdelta, double ydelta, void* param);

// Expand
int		expand_map_size(t_vec2 exp, t_vec2 o, t_ad *ad);
int		contract_map_size(t_vec2 con, t_vec2 o, t_ad *ad);

// Map
void	update_cell_imgs(t_cell *cell, t_ad *ad);
void	update_chrimg(t_cell *cell, t_ad *ad);
void	add_map_border(t_map *map);
void	clear_map(t_map *map);

// Update
void	update(void *param);

// Movement
void	move_cursor(t_vec2 p, t_ad *ad);

// Renderer
void	render_img(t_vec2 p, mlx_image_t *img, t_ad *ad);
void	render_map(t_ad *ad);
void	render_to_terminal(t_ad *ad);
void	render_to_file(t_ad *ad);
void	render_to_clipboard(t_ad *ad);
void	cpy_pixels(mlx_image_t *dst, mlx_image_t *src);

// Utils1
int		is_wall(char c);
int		has_moved(t_vec2 p1, t_vec2 p2);
int		is_valid_tile_coordinate(t_vec2 pos, t_ad *ad);
void	ft_freejoin(char **s1, char *s2);

#endif
