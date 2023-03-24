#include "../chess.h"

int	bishop_move(t_piece *bishop, int x, int y)
{
	if (bishop->x - x == bishop->y - y)
	{
		bishop->x = x;
		bishop->y = y;
		return (1);
	}
	else
		printf("Bishop can not move there");
	return (0);
}

void	bishop_creator(char color, int x)
{
	t_piece	*bishop;

	bishop = malloc(sizeof(t_piece));
	bishop->x = x;
	bishop->y = 7 * (color == 'w');
	if (color == 'w')
		bishop->img = image_creator("Images/WB.xpm");
	else
		bishop->img = image_creator("Images/BB.xpm");
	bishop->display = display_piece;
	bishop->color = color;
	bishop->move = bishop_move;
	bishop->next = NULL;
	add_piece(bishop);
}
