#include "chess.h"

t_piece	*last(int flag)
{
	t_piece *cur;

	if (!flag)
		cur = all.pieces;
	else
		cur = all.dead;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void	add_piece(t_piece *to_add)
{
	if (!all.pieces)
		all.pieces = to_add;
	else
		last(0)->next = to_add;
}