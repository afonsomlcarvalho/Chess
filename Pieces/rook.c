#include "../chess.h"

int	rook_range(t_piece *rook, int x, int y, int flag)
{
	int	x0;
	int	y0;

	x0 = rook->x;
	y0 = rook->y;
	if ((rook->y == y || rook->x == x) && !is_there_piece_same_line(rook, x, y))
	{
		if (flag)
			return (1);
		rook->x = x;
		rook->y = y;
	}
	if (!flag && king_in_check(rook->color, x, y))
	{
		rook->x = x0;
		rook->y = y0;
	}
	return (rook->x == x && rook->y == y);
}

void	rook_creator(int color, int x)
{
	t_piece	*rook;

	rook = malloc(sizeof(t_piece));
	rook->x = x;
	rook->y = 7 * (color == WHITE);
	if (color == WHITE)
		rook->img = image_creator("Images/WR.xpm");
	else
		rook->img = image_creator("Images/BR.xpm");
	rook->display = display_piece;
	rook->color = color;
	rook->moves = 0;
	rook->move = rook_range;
	rook->name = "Rook";
	rook->next = NULL;
	add_piece(rook);
}
