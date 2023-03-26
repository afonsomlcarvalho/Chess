#include "chess.h"

void	pieces_creator()
{
	int	i;

	// bishop_creator(WHITE, 2, 7);
	// bishop_creator(WHITE, 5, 7);
	// bishop_creator(BLACK, 2, 0);
	// bishop_creator(BLACK, 5, 0);
	// knight_creator(WHITE, 1, 7);
	// knight_creator(WHITE, 6, 7);
	// knight_creator(BLACK, 1, 0);
	// knight_creator(BLACK, 6, 0);
	// queen_creator(BLACK, 3, 0);
	// queen_creator(WHITE, 3, 7);
	for (i = 0; i < 8; i++)
	{
		// pawn_creator(BLACK, i, 1);
		pawn_creator(WHITE, i, 3);
	}
	// rook_creator(WHITE, 0, 7);
	// rook_creator(WHITE, 7, 7);
	// rook_creator(BLACK, 0, 0);
	// rook_creator(BLACK, 7, 0);
	king_creator(WHITE, 4, 7);
	king_creator(BLACK, 4, 0);
}

void	select_piece(int x, int y)
{
	t_piece	*cur;

	cur = (all())->pieces;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
		{
			if (cur->color != (all())->turn)
			{
				if (!cur->color)
					printf("It's black's turn.\n");
				else
					printf("It's white's turn.\n");
				return ;
			}
			if ((all())->selected_piece && cur->x == (all())->selected_piece->x && cur->y == (all())->selected_piece->y)
			{
				(all())->selected = 0;
				(all())->selected_piece = 0;
				printf("%s deselected.\n", cur->name);
				return ;
			}
			(all())->selected_piece = cur;
			(all())->selected = 1;
			printf("%s selected.\n", cur->name);
			return ;
		}
		cur = cur->next;
	}
	printf("Select a piece.\n");
}

void	new_turn()
{
	t_piece *cur;

	cur = (all())->pieces;
	(all())->turn = (all())->turn == 0;
	while(cur)
	{
		cur->x = 7 - cur->x;
		cur->y = 7 - cur->y;
		cur = cur->next;
	}
}

int	move(int button, int x, int y, void *a)
{
	if (button == 1 && !(all())->selected)
		select_piece(x / 60, y / 60);
	else if (button == 1)
	{
		if (is_piece(x / 60, y / 60, (all())->selected_piece->color))
			select_piece(x / 60, y / 60);
		else if ((all())->selected_piece->move((all())->selected_piece, x / 60, y / 60, 0))
		{
			(all())->selected = 0;
			(all())->selected_piece->moves++;
			if (is_piece(x / 60, y / 60, !(all())->selected_piece->color))
				eat(x / 60, y / 60, !(all())->selected_piece->color);
			if (!(all())->pawn)
			{
				check();
				new_turn();
			}
		}
		else
			printf("%s can not move there.\n", (all())->selected_piece->name);
	}
	paint();
	return (0);
}

int	end(void *a)
{
	free_all();
	exit(0);
}

int	main()
{
	(all())->mlx = mlx_init();
	(all())->wind = mlx_new_window((all())->mlx, 60 * 8, 60 * 8, "Chess");
	(all())->canva.img = mlx_new_image((all())->mlx, 60 * 8, 60 * 8);
	(all())->canva.addr = mlx_get_data_addr((all())->canva.img, &(all())->canva.bpp, &(all())->canva.ll, &(all())->canva.endian);
	pieces_creator();
	paint();
	mlx_hook((all())->wind, 4, (1L<<2), move, NULL);
	mlx_hook((all())->wind, 17, 0, end, NULL);
	mlx_loop((all())->mlx);
}