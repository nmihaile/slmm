
#include "../include/slmm.h"

static void	ft_print_and_terminate(char *s)
{
	ft_printf(s);
	exit (0);
}

static void	ft_print_help_msg(void)
{
	ft_printf("usage: slmm [-v | -h] map_file\n\n");
	ft_printf("       HOW-TO:\n");
	ft_printf("       Use left mouse btn to place a tile.\n");
	ft_printf("       Select charecters by typing on the keyboard. [A-Z][0-9]\n");
	ft_printf("       Use right mouse btn to delete a tile (puts a floor tile \"0\").\n");
	ft_printf("       \n");
	ft_printf("       KEYBOARD SHORTCUTS:\n");
	ft_printf("       [SHIFT] + [1]          : Surrounds the map with walls (1).\n");
	ft_printf("       [SHIFT] + [0]          : Clear map: fills the map with (0) and surrounds it with walls (1).\n");
	ft_printf("       [CMD]   + [C]          : Copy map to clipboard.\n");
	ft_printf("       --\n");
	ft_printf("       [SHIFT] + [UP ARROW]   : Expands map by 1 row at the top.\n");
	ft_printf("       [SHIFT] + [DOWN ARROW] : Expands map by 1 row at the bottom.\n");
	ft_printf("       [SHIFT] + [LEFT ARROW] : Expands map by 1 column on the left.\n");
	ft_printf("       [SHIFT] + [RIGHT ARROW]: Expands map by 1 column on the right.\n");
	ft_printf("       --\n");
	ft_printf("       [CMD] + [UP ARROW]     : Contract map by 1 row at the bottom.\n");
	ft_printf("       [CMD] + [DOWN ARROW]   : Contract map by 1 row at the top.\n");
	ft_printf("       [CMD] + [LEFT ARROW]   : Contract map by 1 column on the right.\n");
	ft_printf("       [CMD] + [RIGHT ARROW]  : Contract map by 1 column on the left.\n");
	ft_printf("       --\n\n");
	ft_printf("       CUSTOM IMAGES\n");
	ft_printf("       If you want to use your own images, you can just add a 16x16 pixel .png\n");
	ft_printf("       in the folder ./imgs/ with the name of the character.\n");
	ft_printf("       For example \"./imgs/M.png\" would display your image instead of\n");
	ft_printf("       the character \"M\".\n");
	ft_printf("\n");
	ft_printf("       slmm v"VERSION" / made with ❤️  by 42 Heilbronn / written by nmihaile\n");
	ft_printf("\n");
	exit(0);
}

void check_flags(int ac, char **av)
{
	if (ac >= 2)
	{
		if (ft_strnstr(av[1], "-v", 3) || ft_strnstr(av[1], "--version", 10))
			ft_print_and_terminate("So_Long Map Maker version "VERSION"\n");
		if (ft_strnstr(av[1], "-h", 3) || ft_strnstr(av[1], "--help", 10))
			ft_print_help_msg();
	}
}
