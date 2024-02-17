
#include "../include/slmm.h"

int	load_and_set_map_dimensions(char *file, t_ad *ad)
{
	int		w;
	int		h;
	int		fd;
	char	*line;

	w = 0;
	h = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
	{
		if (w == 0)
			w = ft_strlen(line) - 1;
		else
		{
			if (w != (int)ft_strlen(line) - 1)
			{
				free(line);
				return (1);
			}
		}
		h++;
		free (line);
	}
	ad->map.width = w;
	ad->map.height = h;
	free(line);
	return (0);
}

int	load_map_from_file(char *file, t_ad *ad)
{
	int		fd;
	int		y;
	char	*line;

	ad->map.matrix = (t_cell **)calloc((ad->map.height), sizeof(t_cell *));
	if (ad->map.matrix == NULL)
		return (1);

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	y = 0;
	while ((line = get_next_line(fd)))
	{
		line[ft_strlen(line) - 1] = '\0';
		ad->map.matrix[y] = (t_cell *)calloc((ad->map.width), sizeof(t_cell));
		if (ad->map.matrix[y] == NULL)
			return (1);
		for (int x = 0; line[x]; x++)
		{
			ad->map.matrix[y][x].c = line[x];
			if (ad->map.matrix[y][x].c == '1')
				ad->map.matrix[y][x].is_wall = 1;
			else
				ad->map.matrix[y][x].is_wall = 0;
			ad->map.matrix[y][x].tpos = (t_vec2){x, y};
			ad->map.matrix[y][x].cimg = NULL;
			ad->map.matrix[y][x].img = NULL;
		}
		y++;
	}
	close(fd);
	ad->file = ft_strdup(file);
	return (0);
}

int	load_image(char *file, mlx_image_t **img, t_ad *ad)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png(file);
	if (tex == NULL)
		terminate(1, ad);
	*img = mlx_texture_to_image(ad->mlx, tex);
	if (*img == NULL)
		terminate(1, ad);
	mlx_resize_image(*img, TS, TS);
	mlx_delete_texture(tex);
	return (0);
}
