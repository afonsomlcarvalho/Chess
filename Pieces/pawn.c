#include "../chess.h"

int	pawn_range(t_piece *pawn, int x, int y, int flag)
{
	int	x0;
	int	y0;

	x0 = pawn->x;
	y0 = pawn->y;
	if (((x == pawn->x && \
	((pawn->color == WHITE && pawn->y > y && pawn->y <= y + 1 + (pawn->moves == 0)) ||
	(pawn->color == BLACK && pawn->y < y && pawn->y >= y - 1 - (pawn->moves == 0)))) ||
	(modulo(x - pawn->x) == 1 && \
	((pawn->color == WHITE && pawn->y == y + 1 && is_piece(x, y, BLACK)) ||
	(pawn->color == BLACK && pawn->y == y - 1 && is_piece(x, y, WHITE))))) &&\
	!is_there_piece_same_line(pawn, x, y))
	{
		if (flag == 1)
			return (1);
		pawn->x = x;
		pawn->y = y;
	}
	if ((all())->en_passant && modulo(pawn->x - x) == 1 && pawn->y - y == (!pawn->color - pawn->color) && pawn->y == 3 + pawn->color)
		check_en_passant(pawn, x, y);
	if (!flag && king_in_check(pawn->color, x, y))
	{
		pawn->x = x0;
		pawn->y = y0;
	}
	if (modulo(pawn->y - y0) == 2)
		(all())->en_passant = 1;
	else if (pawn->x == x && pawn->y == y)
		(all())->en_passant = 0;
	return (pawn->x == x && pawn->y == y);
}

void	pawn_creator(int color, int x)
{
	t_piece	*pawn;

	pawn = malloc(sizeof(t_piece));
	pawn->x = x;
	pawn->y = 1 + 5 * (color == WHITE);
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
	add_piece(pawn);
}