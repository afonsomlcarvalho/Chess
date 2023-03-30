#include "chess.h"

int	check_pieces_in_between(t_piece *king, int x, int y)
{
	t_piece	*cur;

	cur = (all())->pieces;
	while (cur)
	{
		if ((king->x > x && (cur->x == 1 || cur->x == 2 || (cur->x == 3 && !king->color)) && cur->y == y) || \
			(king->x < x && ((cur->x == 4 && king->color) || cur->x == 5 || cur->x == 6) && cur->y == y))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	no_threat(t_piece *king, int x, int y)
{
	int	i;
	t_piece	*cur;

	for (i = 2 + 3 * (x > king->x) - king->color; i < 4 + 3 * (x > king->x) - king->color; i++)
	{
		cur = (all())->pieces;
		while (cur)
		{
			if (cur->color == !king->color && cur->move(cur, i, y, 1))
				return (0);
			cur = cur->next;
		}
	}
	return (1);
}

void	check_castle(t_piece *king, int x, int y)
{
	t_piece	*rook;

	rook = (all())->pieces;
	while (rook)
	{
		if (rook->x == 7 * (king->x < x) && rook->y == y && rook->moves == 0 && \
			check_pieces_in_between(king, x, y) && \
			no_threat(king, x, y) && !king_in_check(king->color, -1, -1))
		{
			rook->x = x + ((x < king->x) - (x > king->x));
			king->x = x;
			return ;
		}
		rook = rook->next;
	}
}