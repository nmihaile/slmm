
#include "../include/slmm.h"

void	render_img(t_vec2 p, mlx_image_t *img, t_ad *ad)
{
	mlx_image_to_window(ad->mlx, img, p.x * TS, p.y * TS);
}

void	render_map(t_ad *ad)
{
	int x, y;

	y = 0;
	while (y < ad->map.height)
	{
		x = 0;
		while (x < ad->map.width)
		{
			if (ad->map.matrix[y][x].c == '1')
			{
				if (ad->map.matrix[y][x].img == NULL)
				{
					load_image(WALL_FILE, &ad->map.matrix[y][x].img, ad);
					mlx_image_to_window(ad->mlx, ad->map.matrix[y][x].img, x * TS, y * TS);
				}
				else
					mlx_image_to_window(ad->mlx, ad->map.matrix[y][x].img, x * TS, y * TS);
			}
			else // if (ad->map.matrix[y][x].c == '0')
			{
				if (ad->map.matrix[y][x].img == NULL)
				{
					load_image(FLOOR_FILE, &ad->map.matrix[y][x].img, ad);
					mlx_image_to_window(ad->mlx, ad->map.matrix[y][x].img, x * TS, y * TS);
				}
				else
					mlx_image_to_window(ad->mlx, ad->map.matrix[y][x].img, x * TS, y * TS);
			}
			update_chrimg(&ad->map.matrix[y][x], ad);
			x++;
		}
		y++;
	}
	if (ad->cimg)
	{
		mlx_delete_image(ad->mlx, ad->cimg);
		if (load_image(CURSOR_FILE, &ad->cimg, ad))
			terminate(ERROR_LOADING_IMAGE, ad);
		mlx_image_to_window(ad->mlx, ad->cimg, ad->cpos.x * TS, ad->cpos.x * TS);
	}
}

void	render_to_terminal(t_ad *ad)
{
	int x, y;

	y = 0;
	while (y < ad->map.height)
	{
		x = 0;
		while (x < ad->map.width)
		{
			printf("%c", ad->map.matrix[y][x].c);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	render_to_file(t_ad *ad)
{
	int x, y;
	int	fd;

	if (ad->file == NULL)
		return ;
	fd = open(ad->file, O_RDWR | O_CREAT | O_TRUNC, 0644);

	y = 0;
	while (y < ad->map.height)
	{
		x = 0;
		while (x < ad->map.width)
		{
			// printf("%c", ad->map.matrix[y][x].c);
			write(fd, &ad->map.matrix[y][x].c, 1);
			x++;
		}
		// printf("\n");
		write(fd, "\n", 1);
		y++;
	}
	close(fd);
}

void	render_to_clipboard(t_ad *ad)
{
	int x, y;
	char buf[2048];
	int	i;

	i = 0;

	// Check if the code is being compiled on macOS o Linus
	#ifdef __APPLE__
		FILE* pipe = popen("pbcopy", "w");
	#endif

	#ifdef __linux__
		FILE* pipe = popen("xclip -selection clipboard", "w");
	#endif

	if (pipe != NULL)
	{
		y = 0;
		while (y < ad->map.height)
		{
			x = 0;
			while (x < ad->map.width)
			{
				// printf("%c", ad->map.matrix[y][x].c);
				buf[i++] = ad->map.matrix[y][x].c;
				x++;
			}
			// printf("\n");
			buf[i++] = '\n';
			y++;
		}
		buf[i] = 0;
		fwrite(&buf, 1, ft_strlen(buf), pipe);
		pclose(pipe);
	}
	else
	{
		#ifdef __APPLE__
			printf("Failed to open pbcopy.\n");
		#endif

		#ifdef __linux__
			printf("Failed to open xclip.\n");
		#endif
	}
}

void	cpy_pixels(mlx_image_t *dst, mlx_image_t *src)
{
	ft_memcpy(dst->pixels, src->pixels, dst->width * dst->height * 4);
}
