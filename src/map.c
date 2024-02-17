
#include "../include/slmm.h"
#include <sys/unistd.h>

void	update_cell_imgs(t_cell *cell, t_ad *ad)
{
	mlx_delete_image(ad->mlx, cell->cimg);
	mlx_delete_image(ad->mlx, cell->img);
	if (cell->is_wall)
		load_image(WALL_FILE, &cell->img, ad);
	else
		load_image(FLOOR_FILE, &cell->img, ad);
	mlx_image_to_window(ad->mlx, cell->img, cell->tpos.x * TS, cell->tpos.y * TS);
	update_chrimg(cell, ad);
}

void	update_chrimg(t_cell *cell, t_ad *ad)
{
	char 	str[2];
	char	*cfile;		// character img file

	if (cell->cimg)
		mlx_delete_image(ad->mlx, cell->cimg);
	cell->cimg = NULL;
	if (cell->c == '0' || cell->c == '1')
		return ;

	cfile = calloc(20, sizeof(char));
	if (cfile == NULL)
		terminate(1, ad);
	ft_strlcat(cfile, "imgs/", 20);
	ft_strlcat(cfile, &cell->c, 20);
	ft_strlcat(cfile, ".png", 20);
	if (cfile && access(cfile, F_OK | R_OK) == 0)
	{
		load_image(cfile, &cell->cimg, ad);
		mlx_image_to_window(ad->mlx, cell->cimg, cell->tpos.x * TS, cell->tpos.y * TS);
	}
	else
	{
		str[0] = cell->c;
		str[1] = '\0';
		cell->cimg = mlx_put_string(ad->mlx, str, 0, 0);  // ad->cpos.x, ad->cpos.y
		cell->cimg->instances[0].x = cell->img->instances[0].x + TS / 2 - cell->cimg->width / 2;
		cell->cimg->instances[0].y = cell->img->instances[0].y + TS / 2 - cell->cimg->height / 2;
	}

	if (cfile)
		free(cfile);
}

void	add_map_border(t_map *map)
{
	free_map_imgs(map);
	for (int y = 0; y < map->height; y++)
		for (int x = 0; x < map->width; x++)
		{
			if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
			{
				map->matrix[y][x].c = '1';
				map->matrix[y][x].is_wall = 1;
			}
		}
	render_map(getad());
}

void	clear_map(t_map *map)
{
	free_map_imgs(map);
	for (int y = 0; y < map->height; y++)
		for (int x = 0; x < map->width; x++)
		{
			if (y != 0 && y != map->height - 1 && x != 0 && x != map->width - 1)
			{
				map->matrix[y][x].c = '0';
				map->matrix[y][x].is_wall = 0;
			}
		}
	add_map_border(map);
	render_map(getad());
}
