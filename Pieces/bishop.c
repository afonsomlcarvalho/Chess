#include "../chess.h"

int	bishop_range(t_piece *bishop, int x, int y, int flag)
{
	int	x0;
	int	y0;

	x0 = bishop->x;
	y0 = bishop->y;
	if (modulo(bishop->x - x) == modulo(bishop->y - y) && !is_there_piece_diagonal(bishop, x, y, flag))
	{
		if (flag)
			return (1);
		bishop->x = x;
		bishop->y = y;
	}
	if (!flag && king_in_check(bishop->color, x, y))
	{
		bishop->x = x0;
		bishop->y = y0;
	}
	if (bishop->x == x && bishop->y == y)
		(all())->en_passant = 0;
	return (bishop->x == x && bishop->y == y);
}

void	bishop_creator(int color, int x, int y)
{
	t_piece	*bishop;

	bishop = malloc(sizeof(t_piece));
	bishop->x = x;
	bishop->y = y;
	if (color == WHITE)
		bishop->img = image_creator("Images/WB.xpm");
	else
		bishop->img = image_creator("Images/BB.xpm");
	bishop->display = display_piece;
	bishop->color = color;
	bishop->move = bishop_range;
	bishop->name = "Bishop";
	bishop->next = NULL;
	add_piece(bishop);
}
