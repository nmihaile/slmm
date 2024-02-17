
#include "../include/slmm.h"

// watch out that you pass a correct offset value and
// everything is readeble on src with included offset;
// offset should allways be a positiv numebr
// dsto = destOffset // srco = SrcOffset
static void	mapcpy(t_map *dst, t_map *src, t_vec2 dsto, t_vec2 srco)
{
	t_vec2	size;
	if (dsto.x < 0 || dsto.y < 0)
		return ;

	size.x = (dst->width - dsto.x > src->width + srco.x) ? src->width + srco.x : dst->width - dsto.x;
	size.y = (dst->height - dsto.y > src->height + srco.y) ? src->height + srco.y : dst->height - dsto.y;

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			dst->matrix[y + dsto.y][x + dsto.x].c       = src->matrix[y + srco.y][x + srco.x].c;
			dst->matrix[y + dsto.y][x + dsto.x].is_wall = src->matrix[y + srco.y][x + srco.x].is_wall;
		}
	}
}

int	expand_map_size(t_vec2 exp, t_vec2 o, t_ad *ad)
{
	t_map 	nmap;		// new map
	t_cell	**nmat;		// new matrix

	nmap.width =  ad->map.width + exp.x;
	nmap.height =  ad->map.height + exp.y;

	nmat = (t_cell **)calloc((nmap.height), sizeof(t_cell *));
	if (nmat == NULL)
		terminate(ERROR_ALLOCATE, ad);
	for (int y = 0; y < nmap.height; y++)
	{
		nmat[y] = (t_cell *)calloc((nmap.width), sizeof(t_cell));
		if (nmat[y] == NULL)
			terminate(ERROR_ALLOCATE, ad);
	}
	nmap.matrix = nmat;
	init_empty_map(&nmap);
	mapcpy(&nmap, &ad->map, o, (t_vec2){0, 0});
	free_map(&ad->map);
	ad->map.width = nmap.width;
	ad->map.height = nmap.height;
	ad->map.matrix = nmap.matrix;
	mlx_set_window_size(ad->mlx, ad->map.width * TS, ad->map.height * TS);
	t_vec2	wpos;
	mlx_get_window_pos(ad->mlx, &wpos.x, &wpos.y);
	if (o.x > 0)
	{
		mlx_set_window_pos(ad->mlx, wpos.x - TS, wpos.y);
		ad->cpos.x = ad->cpos.x + 1;
	}
	if (o.y > 0)
	{
		mlx_set_window_pos(ad->mlx, wpos.x, wpos.y - TS);
		ad->cpos.y = ad->cpos.y + 1;
	}
	// ad->cpos.x += (ad->cpos.x == 0) ? 0 : exp.x;
	// ad->cpos.y += (ad->cpos.y == 0) ? 0 : exp.y;
	render_map(ad);
	return (0);
}

int	contract_map_size(t_vec2 con, t_vec2 o, t_ad *ad)
{
	t_map 	nmap;		// new map
	t_cell	**nmat;		// new matrix

	if ((con.x && ad->map.width <= 3) || (con.y && ad->map.height <= 3))
		return (0);

	nmap.width =  ad->map.width - con.x;
	nmap.height =  ad->map.height - con.y;

	nmat = (t_cell **)calloc((nmap.height), sizeof(t_cell *));
	if (nmat == NULL)
		terminate(ERROR_ALLOCATE, ad);
	for (int y = 0; y < nmap.height; y++)
	{
		nmat[y] = (t_cell *)calloc((nmap.width), sizeof(t_cell));
		if (nmat[y] == NULL)
			terminate(ERROR_ALLOCATE, ad);
	}
	nmap.matrix = nmat;
	init_empty_map(&nmap);
	mapcpy(&nmap, &ad->map, (t_vec2){0, 0}, o);
	free_map(&ad->map);
	ad->map.width = nmap.width;
	ad->map.height = nmap.height;
	ad->map.matrix = nmap.matrix;
	mlx_set_window_size(ad->mlx, ad->map.width * TS, ad->map.height * TS);
	t_vec2	wpos;
	mlx_get_window_pos(ad->mlx, &wpos.x, &wpos.y);
	if (o.x > 0)
	{
		mlx_set_window_pos(ad->mlx, wpos.x + TS, wpos.y);
		ad->cpos.x = ad->cpos.x - 1;
	}
	if (o.y > 0)
	{
		mlx_set_window_pos(ad->mlx, wpos.x, wpos.y + TS);
		ad->cpos.y = ad->cpos.y - 1;
	}
	if (ad->cpos.x < 0) ad->cpos.x = 0;
	if (ad->cpos.x > ad->map.width - 1) ad->cpos.x = ad->map.width - 1;
	if (ad->cpos.y < 0) ad->cpos.y = 0;
	if (ad->cpos.y > ad->map.height - 1) ad->cpos.y = ad->map.height - 1;
	render_map(ad);
	return (0);



}
