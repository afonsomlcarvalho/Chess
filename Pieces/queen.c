#include "../chess.h"

int	queen_range(t_piece *queen, int x, int y, int flag)
{
	int	x0;
	int	y0;

	x0 = queen->x;
	y0 = queen->y;
	if ((modulo(queen->x - x) == modulo(queen->y - y) || queen->y == y || queen->x == x) && \
	!is_there_piece_diagonal(queen, x, y, flag) && !is_there_piece_same_line(queen, x, y, flag))
	{
		if (flag == 1)
			return (1);
		queen->x = x;
		queen->y = y;
	}
	if (!flag && king_in_check(queen->color, x, y))
	{
		queen->x = x0;
		queen->y = y0;
	}
	if (queen->x == x && queen->y == y)
		all.en_passant = 0;
	return (queen->x == x && queen->y == y);
}

void	queen_creator(int color, int x, int y)
{
	t_piece	*queen;

	queen = malloc(sizeof(t_piece));
	queen->x = x;
	queen->y = y;
	if (color == WHITE)
		queen->img = image_creator("Images/WQ.xpm");
	else
		queen->img = image_creator("Images/BQ.xpm");
	queen->display = display_piece;
	queen->color = color;
	queen->move = queen_range;
	queen->name = "Queen";
	queen->next = NULL;
	queen->value = 9;
	add_piece(queen);
}