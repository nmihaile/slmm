
#include "../include/slmm.h"

static void	print_readable_error(t_error err)
{
	if (err == ERROR_ALLOCATE)
		printf("%s\n", "Failed to allocate memory.");
	else if (err == ERROR_LOADING_IMAGE)
		printf("%s\n", "Failed to load image.");
}

void print_error(t_error error)
{
	printf("Error: %d\n", error);
	print_readable_error(error);
}
