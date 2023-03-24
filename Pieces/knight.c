#include "../chess.h"

int	knight_move(t_piece *knight, int x, int y)
{
	if (!is_piece(x, y, knight->color) && ((modulo(x - knight->x) == 2 && modulo(y - knight->y) == 1) || (modulo(x - knight->x) == 1 && modulo(y - knight->y) == 2)))
	{
		knight->x = x;
		knight->y = y;
		return (1);
	}
	else
		printf("Knight can not move there.\n");
	return (0);
}

void	knight_creator(char color, int x)
{
	t_piece	*knight;

	knight = malloc(sizeof(t_piece));
	knight->x = x;
	knight->y = 7 * (color == 'w');
	if (color == 'w')
		knight->img = image_creator("Images/WKn.xpm");
	else
		knight->img = image_creator("Images/BKn.xpm");
	knight->display = display_piece;
	knight->color = color;
	knight->move = knight_move;
	knight->next = NULL;
	add_piece(knight);
}
