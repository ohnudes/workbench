#ifndef TESTING_H
# define TESTING_H

#include "mlx_macos/mlx.h" // for campus
//#include "mlx_linux/mlx.h" // for linux at home
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define X 800
# define Y 600
# define TITTLE "getting started window"
# define ERROR_MESSAGE "error message yare yare yada"

typedef struct	s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

typedef struct	s_xagent
{
	void	*x_connect;
	void	*x_window;
	t_img	img;
}				t_xagent;


void	gettingstarted();


// UTILS
void	init(t_xagent *xagent);
void	malloc_error(void);


#endif
