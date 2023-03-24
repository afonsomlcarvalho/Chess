#include "chess.h"

t_all	*all(void)
{
	static t_all	a;

	return (&a);
}

t_img	image_creator(char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image((all())->mlx, path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	return (img);
}