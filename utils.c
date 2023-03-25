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

int	modulo(int x)
{
	return (x * ((x > 0) - (x < 0)));
}

int	is_piece(int x, int y, int color)
{
	t_piece	*cur;

	cur = (all())->pieces;
	while (cur)
	{
		if (cur->x == x && cur->y == y && (color == -1 || cur->color == color))
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	is_there_piece_diagonal(t_piece *piece, int x, int y)
{
	if (is_piece(x, y, piece->color))
		return (1);
	x += ((x < piece->x) - (x > piece->x));
	y += ((y < piece->y) - (y > piece->y));
	while (x != piece->x && y != piece->y)
	{
		if (is_piece(x, y, -1))
			return (1);
		x += ((x < piece->x) - (x > piece->x));
		y += ((y < piece->y) - (y > piece->y));
	}
	return (0);
}

int	is_there_piece_same_line(t_piece *piece, int x, int y)
{
	if (is_piece(x, y, piece->color))
		return (1);
	if (y == piece->y)
	{
		x += ((x < piece->x) - (x > piece->x));
		while (x != piece->x)
		{
			if (is_piece(x, y, -1))
				return (1);
			x += ((x < piece->x) - (x > piece->x));
		}
	}
	else if (x == piece->x)
	{
		y += ((y < piece->y) - (y > piece->y));
		while (y != piece->y)
		{
			if (is_piece(x, y, -1))
				return (1);
			y += ((y < piece->y) - (y > piece->y));
		}
	}
	return (0);
}

int	king_in_check(int color)
{
	t_piece	*king;
	t_piece	*cur;

	king = (all())->pieces;
	while (king)
	{
		if (king->color == color && !strncmp(king->name, "King", strlen(king->name)))
			break ;
		king = king->next;
	}
	cur = (all())->pieces;
	while (cur)
	{
		if (cur->color == !king->color && cur->move(cur, king->x, king->y, 1))
			return (1);
		cur = cur->next;
	}
	return (0);
}