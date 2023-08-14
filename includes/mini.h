#ifndef MINILIBX_TEST_H
# define MINILIBX_TEST_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


#define WIDTH 1920
#define HEIGHT 1080

# define PIXEL_BLACK 0x0
# define PIXEL_RED 0xffff
# define PIXEL_AZURE 0xf0ffff
# define PIXEL_GREEN 0xff00
# define PIXEL_GOLD 0xffd700
# define PIXEL_PINK 0xffc0cb
# define PIXEL_PURPLE 0xa020f0
# define PIXEL_SEASHELL 0xfff5ee
# define PIXEL_BISQUE 0xffe4c4
# define PIXEL_MISTYROSE 0xffe4e1
# define PIXEL_HONEY 0xf0fff0

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif