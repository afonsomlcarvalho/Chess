#include "chess.h"

t_piece	*last()
{
	t_piece *cur;

	cur = (all())->pieces;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void	add_piece(t_piece *to_add)
{
	if (!(all())->pieces)
		(all())->pieces = to_add;
	else
		last()->next = to_add;
}