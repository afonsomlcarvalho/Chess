#include "../chess.h"

int	pawn_move(t_piece *pawn, int x, int y)
{
	if ()
	{
		pawn->x = x;
		pawn->y = y;
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
	add_piece(pawn);
}