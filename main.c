#include "chess.h"

void	pieces_creator()
{
	int	i;

	bishop_creator('w', 2);
	bishop_creator('w', 5);
	bishop_creator('b', 2);
	bishop_creator('b', 5);
	knight_creator('w', 1);
	knight_creator('w', 6);
	knight_creator('b', 1);
	knight_creator('b', 6);
	queen_creator('b', 3);
	queen_creator('w', 3);
	for (i = 0; i < 8; i++)
	{
		pawn_creator('b', i);
		pawn_creator('w', i);
	}
	rook_creator('w', 0);
	rook_creator('w', 7);
	rook_creator('b', 0);
	rook_creator('b', 7);
	king_creator('w', 4);
	king_creator('b', 4);
}

void	select_piece(int x, int y)
{
	t_piece	*cur;

	cur = (all())->pieces;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
		{
			(all())->selected_piece = cur;
			(all())->selected = 1;
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
		(all())->selected_piece->move((all())->selected_piece, x / 60, y / 60);
		(all())->selected = 0;
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