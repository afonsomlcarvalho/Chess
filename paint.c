#include "chess.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_color(t_img img, int x, int y)
{
	char	*dst;

	dst = img.addr + (y * img.ll + x * (img.bpp / 8));
	return (*(unsigned int *) dst);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color != -16777216)
	{
		dst = img.addr + (y * img.ll + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	paint_floor()
{
	int	x;
	int	y;

	y = 0;
	while (y < 60 * 8)
	{
		x = 0;
		while (x < 60 * 8)
		{
			if ((!((x / 60) % 2) && !((y / 60) % 2)) || (((x / 60) % 2) && ((y / 60) % 2)))
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00ffce9e);
			else
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00d18b47);
			x++;
		}
		y++;
	}
}

void	display_piece(t_piece *piece)
{
	int	x;
	int	y;

	y = 0;
	while (y < 60)
	{
		x = 0;
		while (x < 60)
		{
			put_pixel_img((all())->canva, x + piece->x * 60, y + piece->y * 60, get_color(piece->img, x, y));
			x++;
		}
		y++;
	}
}

void	paint()
{
	t_piece	*cur;

	paint_floor();
	cur = (all())->pieces;
	while (cur)
	{
		cur->display(cur);
		cur = cur->next;
	}
	mlx_put_image_to_window((all())->mlx, (all())->wind, (all())->canva.img, 0, 0);
}