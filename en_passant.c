#include "chess.h"

void	check_en_passant(t_piece *pawn, int x, int y)
{
	t_piece *cur;

	cur = (all())->pieces;
	while (cur)
	{
		if (!strncmp("Pawn", cur->name, strlen(cur->name)) && cur->x == x && cur->y == pawn->y && cur->color == !pawn->color)
		{
			pawn->x = x;
			pawn->y = y;
			eat(x, cur->y, cur->color);
		}
		cur = cur->next;
	}
}