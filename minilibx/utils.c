
#include "testing.h"

void	malloc_error()
{
	perror(ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}

void	cleanexit(t_xmiddleman *midman)
{
	if (midman->x_connect == NULL)	
		malloc_error();
	else if (midman->x_window == NULL)
	{
		mlx_destroy_display(midman->x_connect);
		malloc_error();
	}
	else if (midman
	return ;
}
