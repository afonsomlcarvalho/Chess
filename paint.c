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
				my_mlx_pixel_put(&(all())->canva, x + 120, y + 120, 0x0092e364);
			else if ((all())->selected && (all())->selected_piece->move((all())->selected_piece, x / 60, y / 60, 1) && \
			((!((x / 60) % 2) && !((y / 60) % 2)) || (((x / 60) % 2) && ((y / 60)% 2))))
				my_mlx_pixel_put(&(all())->canva, x + 120, y + 120, 0x009c7e60);
			else if ((all())->selected && (all())->selected_piece->move((all())->selected_piece, x / 60, y / 60, 1))
				my_mlx_pixel_put(&(all())->canva, x + 120, y + 120, 0x007d532a);
			else if ((!((x / 60) % 2) && !((y / 60) % 2)) || (((x / 60) % 2) && ((y / 60)% 2)))
				my_mlx_pixel_put(&(all())->canva, x + 120, y + 120, 0x00ffce9e);
			else
				my_mlx_pixel_put(&(all())->canva, x + 120, y + 120, 0x00d18b47);
			x++;
		}
		y++;
	}
}

void	display_image(t_img	img, int i, int j)
{
	int	x;
	int	y;

	y = 0;
	while (y < 60)
	{
		x = 0;
		while (x < 60)
		{
			put_pixel_img((all())->canva, x + i, y + j, get_color(img, x, y));
			x++;
		}
		y++;
	}
}

void	display_piece(t_piece *piece)
{
	int	x;
	int	y;

	y = 120;
	while (y - 120 < 60)
	{
		x = 120;
		while (x - 120 < 60)
		{
			put_pixel_img((all())->canva, x + piece->x * 60, y + piece->y * 60, get_color(piece->img, x - 120, y - 120));
			x++;
		}
		y++;
	}
}

void	paint_pawn_menu()
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < 60 * 8)
	{
		x = 0;
		while (x < 60 * 8)
		{
			if ((x < 240 && x >= 120 && y >= 120 && y < 240) || (x >= 240 && x < 360 && y >= 240 && y < 360))
				my_mlx_pixel_put(&(all())->canva, x + 120, y + 120, 0x00ffce9e);
			else if ((x >= 240 && x < 360 && y >= 120 && y < 240) || (x < 240 && x >= 120 && y >= 240 && y < 360))
				my_mlx_pixel_put(&(all())->canva, x + 120, y + 120, 0x00d18b47);
			else
				my_mlx_pixel_put(&(all())->canva, x + 120, y + 120, 0x000000);
			x++;
		}
		y++;
	}
	for (i = 0; i < 4; i++)
		display_image((all())->pawn_pieces[i + 4 * ((all())->selected_piece->color)], 270 + (i > 1) * 120, 270 + (i % 2) * 120);
	mlx_put_image_to_window((all())->mlx, (all())->wind, (all())->canva.img, 0, 0);
	mlx_string_put((all())->mlx, (all())->wind, 320, 210, 0x00ffffff, "Choose a piece:");
}

void	paint_settings()
{
	int	x;
	int	y;

	y = 0;
	while (y < 60 * 12)
	{
		x = 0;
		while (x < 60 * 12)
		{
			if (x > 120 && x < 600 && ((y > 120 && y < 190) || (y > 550 && y < 620)))
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00e6cfd9);
			else
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00d17da4);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((all())->mlx, (all())->wind, (all())->canva.img, 0, 0);
	if ((all())->flip)
		mlx_string_put((all())->mlx, (all())->wind, 160, 160, 0x00000000, "Flip board: ON");
	else
		mlx_string_put((all())->mlx, (all())->wind, 160, 160, 0x00000000, "Flip board: OFF");
	mlx_string_put((all())->mlx, (all())->wind, 160, 590, 0x00000000, "Back to menu");
}

void	paint_menu()
{
	int	x;
	int	y;

	y = 0;
	if ((all())->menu == 2)
		return (paint_settings());
	while (y < 60 * 12)
	{
		x = 0;
		while (x < 60 * 12)
		{
			if (x > 180 && x < 540 && ((y > 240 && y < 310) || (y > 380 && y < 450) || (y > 520 && y < 590)))
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00e6cfd9);
			else
				my_mlx_pixel_put(&(all())->canva, x, y, 0x00d17da4);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((all())->mlx, (all())->wind, (all())->canva.img, 0, 0);
	mlx_string_put((all())->mlx, (all())->wind, 340, 120, 0x00000000, "Chess");
	mlx_string_put((all())->mlx, (all())->wind, 300, 135, 0x00000000, "By Afonso Carvalho");
	mlx_string_put((all())->mlx, (all())->wind, 350, 280, 0x00000000, "Play");
	mlx_string_put((all())->mlx, (all())->wind, 340, 420, 0x00000000, "Settings");
	mlx_string_put((all())->mlx, (all())->wind, 350, 560, 0x00000000, "Quit");
}

void	display_score()
{
	char	*str[2];

	str[0] = ft_itoa((all())->score[0]);
	str[1] = ft_itoa((all())->score[1]);
	mlx_string_put((all())->mlx, (all())->wind, 130, 70, 0xffffffff, str[0]);
	mlx_string_put((all())->mlx, (all())->wind, 430, 70, 0x00000000, str[1]);
	free(str[0]);
	free(str[1]);
}

void	display_dead()
{
	t_piece	*cur;
	int	y[2];
	int	x[2];

	x[0] = 620;
	y[0] = 130;
	x[1] = 20;
	y[1] = 130;
	cur = (all())->dead;
	while (cur)
	{
		if (x[0] == 700)
		{
			x[0] = 620;
			y[0] += 60;
		}
		if (x[1] == 100)
		{
			x[1] = 20;
			y[1] += 60;
		}
		display_image(cur->img, x[cur->color], y[cur->color]);
		x[cur->color] += 40;
		cur = cur->next;
	}
}

void	paint()
{
	t_piece	*cur;

	if ((all())->menu)
		return (paint_menu());
	int	x = 0;
	int	y = 0;
	while (y < 60 * 12)
	{
		x = 0;
		while (x < 60 * 12)
		{
			my_mlx_pixel_put(&(all())->canva, x, y, 0x00d17da4);
			x++;
		}
		y++;
	}
	if ((all())->pawn)
		return (paint_pawn_menu());
	paint_floor();
	cur = (all())->pieces;
	while (cur)
	{
		cur->display(cur);
		cur = cur->next;
	}
	display_dead();
	mlx_put_image_to_window((all())->mlx, (all())->wind, (all())->canva.img, 0, 0);
	display_score();
}