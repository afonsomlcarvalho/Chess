#include "../chess.h"

int	rook_move(t_piece *rook, int x, int y)
{
	if ((rook->y == y || rook->x == x) && !is_there_piece_same_line(rook, x, y))
	{
		rook->x = x;
		rook->y = y;
		rook->moves++;
		return (1);
	}
	else
		printf("Rook can not move there.\n");
	return (0);
}

void	rook_creator(char color, int x)
{
	t_piece	*rook;

	rook = malloc(sizeof(t_piece));
	rook->x = x;
	rook->y = 7 * (color == 'w');
	if (color == 'w')
		rook->img = image_creator("Images/WR.xpm");
	else
		rook->img = image_creator("Images/BR.xpm");
	rook->display = display_piece;
	rook->color = color;
	rook->moves = 0;
	rook->move = rook_move;
	rook->next = NULL;
	add_piece(rook);
}
