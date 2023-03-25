#include "../chess.h"

int	knight_range(t_piece *knight, int x, int y, int flag)
{
	int	x0;
	int	y0;

	x0 = knight->x;
	y0 = knight->y;
	if (!is_piece(x, y, knight->color) && ((modulo(x - knight->x) == 2 && modulo(y - knight->y) == 1) || (modulo(x - knight->x) == 1 && modulo(y - knight->y) == 2)))
	{
		if (flag)
			return (1);
		knight->x = x;
		knight->y = y;
	}
	if (!flag && king_in_check(knight->color, x, y))
	{
		knight->x = x0;
		knight->y = y0;
	}
	return (knight->x == x && knight->y == y);
}

void	knight_creator(int color, int x)
{
	t_piece	*knight;

	knight = malloc(sizeof(t_piece));
	knight->x = x;
	knight->y = 7 * (color == WHITE);
	if (color == WHITE)
		knight->img = image_creator("Images/WKn.xpm");
	else
		knight->img = image_creator("Images/BKn.xpm");
	knight->display = display_piece;
	knight->color = color;
	knight->move = knight_range;
	knight->name = "Knight";
	knight->next = NULL;
	add_piece(knight);
}
