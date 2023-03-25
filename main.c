#include "chess.h"

void	pieces_creator()
{
	int	i;

	bishop_creator(WHITE, 2);
	bishop_creator(WHITE, 5);
	bishop_creator(BLACK, 2);
	bishop_creator(BLACK, 5);
	knight_creator(WHITE, 1);
	knight_creator(WHITE, 6);
	knight_creator(BLACK, 1);
	knight_creator(BLACK, 6);
	queen_creator(BLACK, 3);
	queen_creator(WHITE, 3);
	for (i = 0; i < 8; i++)
	{
		pawn_creator(BLACK, i);
		pawn_creator(WHITE, i);
	}
	rook_creator(WHITE, 0);
	rook_creator(WHITE, 7);
	rook_creator(BLACK, 0);
	rook_creator(BLACK, 7);
	king_creator(WHITE, 4);
	king_creator(BLACK, 4);
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
					printf("It's whithe's turn.\n");
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
			(all())->turn = (all())->turn == 0;
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