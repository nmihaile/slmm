
#include "../include/slmm.h"

static int	arrow_keys_are_pressed(mlx_key_data_t keydata)
{
	int	keys[4] = {MLX_KEY_UP, MLX_KEY_DOWN, MLX_KEY_LEFT, MLX_KEY_RIGHT};

	for (int i = 0; i < 4; i++)
	{
		if ((int)keydata.key == keys[i] && keydata.action == MLX_PRESS)
			return (1);
	}
	return (0);
}

void slmm_key_hook(mlx_key_data_t keydata, void *param)
{
	t_ad	*ad;

	ad =(t_ad *)param;

	if (arrow_keys_are_pressed(keydata))
		mlx_set_cursor_mode(ad->mlx, MLX_MOUSE_DISABLED);

	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)) // || (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		mlx_close_window(ad->mlx);

	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SHIFT))
	{
		// EXPAND LEFT
		expand_map_size((t_vec2){1,0}, (t_vec2){1,0}, ad);
		return ;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SHIFT))
	{
		// EXPAND RIGHT
		expand_map_size((t_vec2){1,0}, (t_vec2){0,0}, ad);
		return ;
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SHIFT))
	{
		// EXPAND UP
		expand_map_size((t_vec2){0,1}, (t_vec2){0,1}, ad);
		return ;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SHIFT))
	{
		// EXPAND DOWN
		expand_map_size((t_vec2){0,1}, (t_vec2){0,0}, ad);
		return ;
	}

	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SUPER))
	{
		// SHRINK LEFT
		contract_map_size((t_vec2){1, 0}, (t_vec2){1, 0}, ad);
		return ;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SUPER))
	{
		// SHRINK RIGHT
		contract_map_size((t_vec2){1, 0}, (t_vec2){0, 0}, ad);
		return ;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SUPER))
	{
		// SHRINK TOP
		contract_map_size((t_vec2){0, 1}, (t_vec2){0, 1}, ad);
		return ;
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SUPER))
	{
		// SHRINK BOTTOM
		contract_map_size((t_vec2){0, 1}, (t_vec2){0, 0}, ad);
		return ;
	}

	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SUPER))
	{
		render_to_clipboard(ad);
		return ;
	}

	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SHIFT))
	{
		// add Border
		add_map_border(&ad->map);
		return ;
	}
	if (keydata.key == MLX_KEY_0 && keydata.action == MLX_PRESS && mlx_is_key_down(ad->mlx, MLX_KEY_LEFT_SHIFT))
	{
		// Clear map
		char	command[256];
		int		clearmap;

		#ifdef __APPLE__
			sprintf(command, "osascript -e 'Tell application \"System Events\" to display dialog \"Do you really want to CLEAR THE MAP?\" buttons {\"Yes\", \"No\"} default button 1' -e 'button returned of result'");
		#endif

		#ifdef __linux__
			sprintf(command, "zenity --question --text=\"Do you really want to CLEAR THE MAP?\"");
		#endif

		FILE *pipe = popen(command, "r");
		char buffer[128];
		fgets(buffer, sizeof(buffer), pipe);
		clearmap = (ft_strncmp(buffer, "Yes", 3) == 0 || ft_strncmp(buffer, "yes", 3) == 0);
		pclose(pipe);

		if (clearmap)
			clear_map(&ad->map);
		mlx_focus(ad->mlx);
		return ;
	}

	if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) && ad->cpos.x > 0)
		ad->cpos.x--;
	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) && ad->cpos.x < ad->map.width - 1)
		ad->cpos.x++;
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) && ad->cpos.y > 0)
		ad->cpos.y--;
	if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS) && ad->cpos.y < ad->map.height - 1)
		ad->cpos.y++;

	if (ft_isalnum(keydata.key) && keydata.action == MLX_PRESS)
	{
		ad->lastc = (char)keydata.key;
		if (keydata.key == MLX_KEY_1 && !is_wall(ad->map.matrix[ad->cpos.y][ad->cpos.x].is_wall))
		{
			ad->map.matrix[ad->cpos.y][ad->cpos.x].is_wall = 1;
			cpy_pixels(ad->map.matrix[ad->cpos.y][ad->cpos.x].img, ad->images[0]);
		}
		else if (keydata.key != MLX_KEY_1 && ad->map.matrix[ad->cpos.y][ad->cpos.x].is_wall)
		{
			ad->map.matrix[ad->cpos.y][ad->cpos.x].is_wall = 0;
			cpy_pixels(ad->map.matrix[ad->cpos.y][ad->cpos.x].img, ad->images[1]);
		}
		ad->map.matrix[ad->cpos.y][ad->cpos.x].c = keydata.key;
		free_map_imgs(&ad->map);
		render_map(ad);
		// update_chrimg(&ad->map.matrix[ad->cpos.y][ad->cpos.x], ad);
	}
}


// void slmm_scroll_hook(double xdelta, double ydelta, void* param)
// {
// 	if (xdelta || ydelta || param) {}
// 	mlx_set_cursor_mode(getad()->mlx, MLX_MOUSE_NORMAL);
// }



void	slmm_mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
	t_ad	*ad;
	t_vec2	mpos;

	ad = (t_ad *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS && mods >= 0)
	{
		ad->mpressed = 1;
		mlx_get_mouse_pos(ad->mlx, &mpos.x, &mpos.y);
		mpos.x = mpos.x / TILE_SIZE / SCALE;
		mpos.y = mpos.y / TILE_SIZE / SCALE;
		if (is_valid_tile_coordinate(mpos, ad))
		{
			ad->map.matrix[mpos.y][mpos.x].c = ad->lastc;
			if (ad->lastc == 1)
				ad->map.matrix[mpos.y][mpos.x].is_wall = 1;
			else
				ad->map.matrix[mpos.y][mpos.x].is_wall = 0;
			free_map_imgs(&ad->map);
			render_map(ad);
		}
	}
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS && mods >= 0)
	{
		ad->mpressed = 2;
		mlx_get_mouse_pos(ad->mlx, &mpos.x, &mpos.y);
		mpos.x = mpos.x / TILE_SIZE / SCALE;
		mpos.y = mpos.y / TILE_SIZE / SCALE;
		if (is_valid_tile_coordinate(mpos, ad))
		{
			ad->map.matrix[mpos.y][mpos.x].c = '0';
			ad->map.matrix[mpos.y][mpos.x].is_wall = 0;
			free_map_imgs(&ad->map);
			render_map(ad);
		}
	}
	if ((button == MLX_MOUSE_BUTTON_LEFT || button == MLX_MOUSE_BUTTON_RIGHT) && action == MLX_RELEASE && mods >= 0)
		ad->mpressed = 0;
}
