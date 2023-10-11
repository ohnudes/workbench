
#include "testing.h"

void	init(t_xagent *xagent)
{
	xagent->x_connect = mlx_init(); // stablish connection
	if (xagent->x_connect == NULL)	
		malloc_error();
	xagent->x_window = mlx_new_window(xagent->x_connect, X, Y, TITTLE); // create window
	if (xagent->x_window == NULL)
	{
		// LINUX mlx_destroy_display(xagent->x_connect);
		free(xagent->x_connect);
		malloc_error();
	}
	xagent->img.img_ptr = mlx_new_image(xagent->x_connect, X, Y); // init img.img_ptr
	if (xagent->img.img_ptr == NULL)
	{
		mlx_destroy_window(xagent->x_window, xagent->x_connect);
		// LINUX mlx_destroy_display(xagent->x_connect);
		free(xagent->x_connect);
		malloc_error();
	}
}

void	gettingstarted()
{
	t_xagent	xagent;

	xagent = (t_xagent){};
	init(&xagent);
}
