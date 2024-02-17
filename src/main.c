
#include "../include/slmm.h"

t_ad	*getad()
{
	static t_ad	ad;
	return (&ad);
}

void	free_map_imgs(t_map *map)
{
	for (int y = 0; y < map->height; y++)
		for (int x = 0; x < map->width; x++)
		{
			mlx_delete_image(getad()->mlx, map->matrix[y][x].img);
			map->matrix[y][x].img = NULL;
			mlx_delete_image(getad()->mlx, map->matrix[y][x].cimg);
			map->matrix[y][x].cimg = NULL;
		}
}

void	free_map(t_map *map)
{
	free_map_imgs(map);
	for (int y = 0; y < map->height; y++)
		free(map->matrix[y]);
	free(map->matrix);
}

void	free_images(t_ad *ad)
{
	// Free map images
	for (int y = 0; y < ad->map.height; y++) {
		for (int x = 0; x < ad->map.width; x++) {
			mlx_delete_image(ad->mlx, ad->map.matrix[y][x].img);
			mlx_delete_image(ad->mlx, ad->map.matrix[y][x].cimg);
		}
	}
	for (int it = 0; it < MAX_IMAGES; it++) {
		if (ad->images[it])
			mlx_delete_image(ad->mlx, ad->images[it]);
	}
	mlx_delete_image(ad->mlx, ad->cimg);
}

void	free_ad(t_ad *ad)
{
	int	i;

	if (ad->map.matrix)
	{
		i = 0;
		while (i < ad->map.height)
		{
			if (ad->map.matrix[i])
				free(ad->map.matrix[i]);
			i++;
		}
		free (ad->map.matrix);
	}
	if (ad->file)
		free(ad->file);
}

void	terminate(int error, t_ad *ad)
{
	if (error)
		print_error(error);

	// IN_PROGRESS: FREE STUFF HERE
	free_images(ad);
	free_ad(ad);

	exit (0);
}

void leaks(void)
{
	system("leaks slmm");
}

int	main(int ac, char **av)
{
	check_flags(ac, av);

	// atexit(leaks);
	init_ad();
	init_file(ac, av, getad());
	init_mlx_window(getad());
	init_tiles(getad());

	render_map(getad());

	printf("Let's start building…\n");

	mlx_key_hook(getad()->mlx, slmm_key_hook, getad());
	// mlx_scroll_hook(getad()->mlx, slmm_scroll_hook, getad());
	mlx_mouse_hook(getad()->mlx, slmm_mouse_hook, getad());
	mlx_loop_hook(getad()->mlx, update, getad());
	mlx_loop(getad()->mlx);

	if (getad()->file)
	{
		render_to_file(getad());
		ft_printf(GREEN"Map was saved in file: "CYAN"%s\n"RESET, getad()->file);
		// OPTIONAL render map to terminal here:
		// render_to_terminal(getad());
	}
	else
		render_to_terminal(getad());

	free_ad(getad());
	if (getad()->mlx)
		mlx_terminate(getad()->mlx);
	return (0);
}
