#include "../chess.h"

int	king_range(t_piece *king, int x, int y, int flag)
{
	int	x0;
	int	y0;

	x0 = king->x;
	y0 = king->y;
	if ((modulo(king->x - x) == modulo(king->y - y) || king->y == y || king->x == x) && \
	!is_there_piece_diagonal(king, x, y, flag) && !is_there_piece_same_line(king, x, y, flag) && \
	modulo(king->x - x) <= 1 && modulo(king->y - y) <= 1)
	{
		if (flag == 1)
			return (1);
		king->x = x;
		king->y = y;
	}
	if (!flag && king->moves == 0 && modulo(king->x - x) == 2 && king->y == y)
		check_castle(king, x, y);
	if (!flag && king_in_check(king->color, x, y))
	{
		king->x = x0;
		king->y = y0;
	}
	if (king->x == x && king->y == y)
		(all())->en_passant = 0;
	return (king->x == x && king->y == y);
}

void	king_creator(int color, int x, int y)
{
	t_piece	*king;

	king = malloc(sizeof(t_piece));
	king->x = x;
	king->y = y;
	if (color == WHITE)
		king->img = image_creator("Images/WKg.xpm");
	else
		king->img = image_creator("Images/BKg.xpm");
	king->display = display_piece;
	king->color = color;
	king->move = king_range;
	king->name = "King";
	king->next = NULL;
	add_piece(king);
}
