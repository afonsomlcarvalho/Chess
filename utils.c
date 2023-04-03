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

int	is_there_piece_diagonal(t_piece *piece, int x, int y, int flag)
{
	if (!flag && is_piece(x, y, piece->color))
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

int	is_there_piece_same_line(t_piece *piece, int x, int y, int flag)
{
	if (!flag && is_piece(x, y, piece->color))
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

void	update_score(void)
{
	(all())->score[!last(1)->color] += last(1)->value;
}

void	add_dead(t_piece *to_add)
{
	t_piece *cur;

	if (!(all())->dead)
		(all())->dead = to_add;
	else
		last(1)->next = to_add;
	update_score();
}

void	eat(int x, int y, int color)
{
	t_piece	*cur;
	t_piece	*temp;

	cur = (all())->pieces;
	if (cur->color == color && cur->x == x && cur->y == y)
	{
		(all())->pieces = cur->next;
		cur->next = NULL;
		add_dead(cur);
		return ;
	}
	while (cur->next)
	{
		if (cur->next->color == color && cur->next->x == x && cur->next->y == y)
		{
			temp = cur->next->next;
			cur->next->next = NULL;
			add_dead(cur->next);
			cur->next = temp;
			break ;
		}
		cur = cur->next;
	}
}

char	*ft_itoa(int n)
{
	int	c = 1;
	int	i = 0;
	int	nbr = n;
	char	*str;

	while (nbr > 9)
	{
		c++;
		nbr /= 10;
	}
	str = malloc(c + 1);
	str[c] = 0;
	while (--c >= 0)
	{
		str[c] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
