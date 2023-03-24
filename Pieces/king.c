#include "../chess.h"

int	king_move(t_piece *king, int x, int y)
{
	if ((modulo(king->x - x) == modulo(king->y - y) || king->y == y || king->x == x) && \
	!is_there_piece_diagonal(king, x, y) && !is_there_piece_same_line(king, x, y) && \
	modulo(king->x - x) <= 1 && modulo(king->y - y) <= 1)
	{
		king->x = x;
		king->y = y;
		return (1);
	}
	else
		printf("King can not move there.\n");
	return (0);
}

void	king_creator(char color, int x)
{
	t_piece	*king;

	king = malloc(sizeof(t_piece));
	king->x = x;
	king->y = 7 * (color == 'w');
	if (color == 'w')
		king->img = image_creator("Images/WKg.xpm");
	else
		king->img = image_creator("Images/BKg.xpm");
	king->display = display_piece;
	king->color = color;
	king->move = king_move;
	king->next = NULL;
	add_piece(king);
}