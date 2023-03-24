#include "../chess.h"

int	queen_move(t_piece *queen, int x, int y)
{
	if ((modulo(queen->x - x) == modulo(queen->y - y) || queen->y == y || queen->x == x) && \
	!is_there_piece_diagonal(queen, x, y) && !is_there_piece_same_line(queen, x, y))
	{
		queen->x = x;
		queen->y = y;
		return (1);
	}
	else
		printf("Queen can not move there.\n");
	return (0);
}

void	queen_creator(char color, int x)
{
	t_piece	*queen;

	queen = malloc(sizeof(t_piece));
	queen->x = x;
	queen->y = 7 * (color == 'w');
	if (color == 'w')
		queen->img = image_creator("Images/WQ.xpm");
	else
		queen->img = image_creator("Images/BQ.xpm");
	queen->display = display_piece;
	queen->color = color;
	queen->move = queen_move;
	queen->next = NULL;
	add_piece(queen);
}