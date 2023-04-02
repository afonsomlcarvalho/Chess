#include "../chess.h"

int	pawn_range(t_piece *pawn, int x, int y, int flag)
{
	int	x0;
	int	y0;
	int	direction;

	x0 = pawn->x;
	y0 = pawn->y;
	direction = (((all())->flip && pawn->color == (all())->turn) || (!(all())->flip && !pawn->color)) - !(((all())->flip && pawn->color == (all())->turn) || (!(all())->flip && !pawn->color));
	if ((pawn->x == x && pawn->y == y + direction && !is_piece(x, y, -1)) || \
		(pawn->moves == 0 && pawn->x == x && pawn->y == y + 2 * direction && !is_there_piece_same_line(pawn, x, y, 0)) || \
		(modulo(pawn->x - x) == 1 && pawn->y == y + direction && is_piece(x, y, !pawn->color)))
	{
		if (flag == 1)
			return (1);
		pawn->x = x;
		pawn->y = y;
	}
	if ((all())->en_passant && modulo(pawn->x - x) == 1 && pawn->y - y == direction && pawn->y == 3 + (!(all())->flip && pawn->color))
		check_en_passant(pawn, x, y);
	if (!flag && king_in_check(pawn->color, x, y))
	{
		pawn->x = x0;
		pawn->y = y0;
	}
	if (!flag && modulo(pawn->y - y0) == 2)
		(all())->en_passant = 1;
	else if (!flag && pawn->x == x && pawn->y == y)
		(all())->en_passant = 0;
	if (!flag && pawn->y == 0)
		(all())->pawn = 1;
	return (pawn->x == x && pawn->y == y);
}

void	pawn_creator(int color, int x, int y)
{
	t_piece	*pawn;

	pawn = malloc(sizeof(t_piece));
	pawn->x = x;
	pawn->y = y;
	if (color == WHITE)
		pawn->img = image_creator("Images/WP.xpm");
	else
		pawn->img = image_creator("Images/BP.xpm");
	pawn->display = display_piece;
	pawn->color = color;
	pawn->move = pawn_range;
	pawn->name = "Pawn";
	pawn->next = NULL;
	pawn->moves = 0;
	pawn->value = 1;
	add_piece(pawn);
}