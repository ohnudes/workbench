#ifndef TESTING_H
# define TESTING_H

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define X 800
# define Y 600
# define TITTLE "getting started window"

typedef struct	s_xmiddleman
{
	void	*x_connect;
	void	*x_window;
}				t_xmiddleman;

void	gettingstarted();


// UTILS
void	cleanexit(t_xmiddleman *midman);


#endif
