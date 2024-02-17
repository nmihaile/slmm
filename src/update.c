
#include "../include/slmm.h"

static void	update_cursor_img(t_ad *ad)
{
	mlx_delete_image(ad->mlx, ad->cimg);
	load_image(CURSOR_FILE, &ad->cimg, ad);
	mlx_image_to_window(ad->mlx, ad->cimg, ad->cpos.x, ad->cpos.y);
}

void	update(void *param)
{
	t_ad	*ad;
	t_vec2	mpos;
	char	new_c;

	ad = (t_ad *)param;

	mpos = (t_vec2){0};
	mlx_get_mouse_pos(ad->mlx, &mpos.x, &mpos.y);
	if (has_moved(ad->ompos, mpos))
	{
		mlx_set_cursor_mode(getad()->mlx, MLX_MOUSE_NORMAL);

		if (mpos.x >= 0 && mpos.x <= ad->mlx->width && mpos.y >= 0 && mpos.y <= ad->mlx->height)
		{
			ad->cpos.x = (int)(mpos.x / TILE_SIZE / SCALE);
			ad->cpos.y = (int)(mpos.y / TILE_SIZE / SCALE);
		}
		ad->ompos = mpos;

		new_c = 0;
		if (ad->mpressed == 1)
			new_c = ad->lastc;
		else if (ad->mpressed == 2)
			new_c = '0';

		if (is_valid_tile_coordinate(ad->cpos, ad) && ad->mpressed && ad->map.matrix[ad->cpos.y][ad->cpos.x].c != new_c)
		{
			ad->map.matrix[ad->cpos.y][ad->cpos.x].c = new_c;
			if (ad->map.matrix[ad->cpos.y][ad->cpos.x].c == '1')
				ad->map.matrix[ad->cpos.y][ad->cpos.x].is_wall = 1;
			else
				ad->map.matrix[ad->cpos.y][ad->cpos.x].is_wall = 0;
			update_cell_imgs(&ad->map.matrix[ad->cpos.y][ad->cpos.x], ad);
			update_cursor_img(ad);
		}
	}

	ad->cimg->instances[0].x = ad->cpos.x * TS;
	ad->cimg->instances[0].y = ad->cpos.y * TS;
}
