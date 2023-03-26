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
			if ((all())->selected && x / 60 == (all())->selected_piece->x && y / 60 == (all())->selected_piece->y)
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00ff0000);
			// else if ((all())->selected && (all())->selected_piece->move((all())->selected_piece, x / 60, y / 60, 1) && \
			// ((!((x / 60) % 2) && !((y / 60) % 2)) || (((x / 60) % 2) && ((y / 60)% 2))))
			// 	my_mlx_pixel_put(&(all())->canva, x, y, 0x0000ff00);
			// else if ((all())->selected && (all())->selected_piece->move((all())->selected_piece, x / 60, y / 60, 1))
			// 	my_mlx_pixel_put(&(all())->canva, x, y, 0x0000cc00);
			else if ((!((x / 60) % 2) && !((y / 60) % 2)) || (((x / 60) % 2) && ((y / 60)% 2)))
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

void	paint_pawn_menu()
{
	int	x;
	int	y;

	y = 0;
	while (y < 60 * 8)
	{
		x = 0;
		while (x < 60 * 8)
		{
			if ((x < 240 && x >= 120 && y >= 120 && y < 240) || (x >= 240 && x < 360 && y >= 240 && y < 360))
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00ffce9e);
			else if ((x >= 240 && x < 360 && y >= 120 && y < 240) || (x < 240 && x >= 120 && y >= 240 && y < 360))
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00d18b47);
			else
				my_mlx_pixel_put(&(all())->canva, x, y, 0x000000);
			x++;
		}
		y++;
	}
	
	mlx_put_image_to_window((all())->mlx, (all())->wind, (all())->canva.img, 0, 0);
	mlx_string_put((all())->mlx, (all())->wind, 200, 90, 0x00ffffff, "Choose a piece:");
}

void	paint()
{
	t_piece	*cur;

	if ((all())->pawn)
		return (paint_pawn_menu());
	paint_floor();
	cur = (all())->pieces;
	while (cur)
	{
		cur->display(cur);
		cur = cur->next;
	}
	mlx_put_image_to_window((all())->mlx, (all())->wind, (all())->canva.img, 0, 0);
}