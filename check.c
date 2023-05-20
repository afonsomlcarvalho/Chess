#include "chess.h"

int	king_in_check(int color, int x, int y)
{
	t_piece	*king;
	t_piece	*cur;

	king = all.pieces;
	cur = all.pieces;
	while (king)
	{
		if (king->color == color && !strncmp(king->name, "King", strlen(king->name)))
			break ;
		king = king->next;
	}
	while (cur)
	{
		if ((cur->x != x || cur->y != y) && cur->color == !king->color && cur->move(cur, king->x, king->y, 1))
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	check_all_possibilities(int	color)
{
	t_piece	*cur;
	int	x;
	int	y;
	int	x0;
	int	y0;
	int	en_passant;
	int	pawn;

	en_passant = all.en_passant;
	pawn = all.pawn;
	cur = all.pieces;
	while (cur)
	{
		y = 0;
		x0 = cur->x;
		y0 = cur->y;
		while (cur->color == color && y < 8)
		{
			x = 0;
			while (x < 8)
			{
				if ((cur->x != x || cur->y != y) && cur->move(cur, x, y, 0))
				{
					cur->x = x0;
					cur->y = y0;
					all.en_passant = en_passant;
					all.pawn = pawn;
					return (1);
				}
				x++;
			}
			y++;
		}
		cur = cur->next;
	}
	return (0);
}

void	check()
{
	if (!check_all_possibilities(!all.selected_piece->color) && king_in_check(!all.selected_piece->color, -1, -1))
		printf("Checkmate!\n");
	else if (!check_all_possibilities(!all.selected_piece->color))
		printf("Stalemate!\n");
	else if (king_in_check(!all.selected_piece->color, -1, -1))
		printf("Check!\n");
}
