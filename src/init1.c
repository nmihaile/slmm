
#include "../include/slmm.h"

void	init_ad(void)
{
	t_ad	*ad;
	ad = getad();
	ad->lastc = '1';
	ad->mpressed = 0;
	ad->file = NULL;
}

int	init_empty_map(t_map *map)
{
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			map->matrix[y][x].cimg = NULL;
			map->matrix[y][x].img = NULL;
			map->matrix[y][x].tpos = (t_vec2){x, y};
			map->matrix[y][x].is_wall = 0;
			map->matrix[y][x].c = '0';
		}
	}
	return (0);
}

int	init_map_default_characters(t_ad *ad)
{
	int	x;
	int	y;

	y = 0;
	while (y < ad->map.height)
	{
		x = 0;
		while (x < ad->map.width)
		{
			ad->map.matrix[y][x].tpos = (t_vec2){x, y};
			if (y == 0 || y == ad->map.height - 1)
			{
				ad->map.matrix[y][x].c = '1';
				ad->map.matrix[y][x].is_wall = 1;
			}
			else if (x == 0 || x == ad->map.width - 1)
			{
				ad->map.matrix[y][x].c = '1';
				ad->map.matrix[y][x].is_wall = 1;
			}
			else
			{
				ad->map.matrix[y][x].c = '0';
				ad->map.matrix[y][x].is_wall = 0;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	init_default_map(t_ad *ad)
{
	int	i;

	ad->map.width = 10;
	ad->map.height = 10;
	ad->map.matrix = (t_cell **)calloc((ad->map.height), sizeof(t_cell *));
	if (ad->map.matrix == NULL)
		return (1);
	i = 0;
	while (i < ad->map.height)
	{
		ad->map.matrix[i] = (t_cell *)calloc((ad->map.width), sizeof(t_cell));
		if (ad->map.matrix[i] == NULL)
			return (1);
		i++;
	}
	init_map_default_characters(ad);
	return (0);
}

int	init_file(int ac, char **av, t_ad *ad)
{
	if (ac <= 1)
	{
		// No file was passed, so we have to create a new default map
		if (init_default_map(ad))
			return (1);
	}
	else
	{
		// A parameter was passed, so we have to load the given map
		int err;
		if ((err = load_and_set_map_dimensions(av[1], ad)))
		{
			if (init_default_map(ad))
				return (1);
			ad->file = ft_strdup(av[1]);
			if (ad->file)
				return (0);
			else
				return (1);
		}
		if ((err = load_map_from_file(av[1], ad)))
		{
			if (init_default_map(ad))
				return (1);
			return (0);
		}
	}
	return (0);
}

int	init_mlx_window(t_ad *ad)
{
	ad->mlx = mlx_init(ad->map.width * TILE_SIZE * SCALE, ad->map.height * TILE_SIZE * SCALE, "so_long map maker", false);
	if (ad->mlx == NULL)
		terminate(1, ad);
	return (0);
}

int	init_tiles(t_ad *ad)
{
	int	x;
	int	y;

	y = 0;
	while (y < ad->map.height)
	{
		x = 0;
		while (x < ad->map.width)
		{
			if (ad->map.matrix[y][x].c == '1')
			{
				if (load_image(WALL_FILE, &ad->map.matrix[y][x].img, ad))
					terminate(ERROR_LOADING_IMAGE, ad);
			}
			else if (ad->map.matrix[y][x].c == '0')
			{
				if (load_image(FLOOR_FILE, &ad->map.matrix[y][x].img, ad))
					terminate(ERROR_LOADING_IMAGE, ad);
			}
			x++;
		}
		y++;
	}
	if (load_image(WALL_FILE, &ad->images[0], ad))
		terminate(ERROR_LOADING_IMAGE, ad);
	if (load_image(FLOOR_FILE, &ad->images[1], ad))
		terminate(ERROR_LOADING_IMAGE, ad);
	if (load_image(CURSOR_FILE, &ad->cimg, ad))
		terminate(ERROR_LOADING_IMAGE, ad);
	return (0);
}
