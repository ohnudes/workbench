
#include "testing.h"

void	gettingstarted()
{
	t_xmiddleman	midman;

	midman = (t_xmiddleman){};
	midman.x_connect = mlx_init();
	midman.x_window = mlx_new_window(midman.x_connect, X, Y, TITTLE);

}
