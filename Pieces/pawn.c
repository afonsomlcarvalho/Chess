#include "../chess.h"

int	pawn_move(t_piece *pawn, int x, int y)
{
	if (((x == pawn->x && \
	((pawn->color == 'w' && pawn->y > y && pawn->y <= y + 1 + (pawn->moves == 0)) ||
	(pawn->color == 'b' && pawn->y < y && pawn->y >= y - 1 - (pawn->moves == 0)))) ||
	(modulo(x - pawn->x) == 1 && \
	((pawn->color == 'w' && pawn->y == y + 1 && is_piece(x, y, 'b')) ||
	(pawn->color == 'b' && pawn->y == y - 1 && is_piece(x, y, 'w'))))) &&\
	!is_there_piece_same_line(pawn, x, y))
	{
		pawn->x = x;
		pawn->y = y;
		pawn->moves++;
		return (1);
	}
	else
		printf("Pawn can not move there.\n");
	return (0);
}

void	pawn_creator(char color, int x)
{
	t_piece	*pawn;

	pawn = malloc(sizeof(t_piece));
	pawn->x = x;
	pawn->y = 1 + 5 * (color == 'w');
	if (color == 'w')
		pawn->img = image_creator("Images/WP.xpm");
	else
		pawn->img = image_creator("Images/BP.xpm");
	pawn->display = display_piece;
	pawn->color = color;
	pawn->move = pawn_move;
	pawn->next = NULL;
	pawn->moves = 0;
	add_piece(pawn);
}