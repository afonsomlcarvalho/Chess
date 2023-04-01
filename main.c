#include "chess.h"

void	pieces_creator()
{
	int	i;

	bishop_creator(WHITE, 2, 7);
	bishop_creator(WHITE, 5, 7);
	bishop_creator(BLACK, 2, 0);
	bishop_creator(BLACK, 5, 0);
	knight_creator(WHITE, 1, 7);
	knight_creator(WHITE, 6, 7);
	knight_creator(BLACK, 1, 0);
	knight_creator(BLACK, 6, 0);
	queen_creator(BLACK, 3, 0);
	queen_creator(WHITE, 3, 7);
	for (i = 0; i < 8; i++)
	{
		pawn_creator(BLACK, i, 1);
		pawn_creator(WHITE, i, 6);
	}
	rook_creator(WHITE, 0, 7);
	rook_creator(WHITE, 7, 7);
	rook_creator(BLACK, 7, 0);
	rook_creator(BLACK, 0, 0);
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

void	pawn_trade(int x, int y)
{
	int	x0;
	int	y0;
	int	color;

	if (x < 120 || x > 360 || y < 120 || y > 360)
		return ;
	x0 = (all())->selected_piece->x;
	y0 = (all())->selected_piece->y;
	color = (all())->selected_piece->color;
	eat((all())->selected_piece->x, (all())->selected_piece->y, (all())->selected_piece->color);
	if (x <= 240 && y <= 240)
		queen_creator(color, x0, y0);
	if (x <= 240 && y > 240)
		rook_creator(color, x0, y0);
	if (x > 240 && y <= 240)
		bishop_creator(color, x0, y0);
	if (x > 240 && y > 240)
		knight_creator(color, x0, y0);
	(all())->pawn = 0;
	paint();
	check();
	new_turn();
}

int	move(int button, int x, int y, void *a)
{
	if (button == 1 && !(all())->selected && !(all())->pawn)
		select_piece(x / 60, y / 60);
	else if (button == 1)
	{
		if ((all())->pawn)
			pawn_trade(x, y);
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
	(all())->pawn_pieces[0] = image_creator("Images/WQ.xpm");
	(all())->pawn_pieces[1] = image_creator("Images/WR.xpm");
	(all())->pawn_pieces[2] = image_creator("Images/WB.xpm");
	(all())->pawn_pieces[3] = image_creator("Images/WKn.xpm");
	(all())->pawn_pieces[4] = image_creator("Images/BQ.xpm");
	(all())->pawn_pieces[5] = image_creator("Images/BR.xpm");
	(all())->pawn_pieces[6] = image_creator("Images/BB.xpm");
	(all())->pawn_pieces[7] = image_creator("Images/BKn.xpm");
	(all())->menu = 1;
	pieces_creator();
	paint();
	mlx_hook((all())->wind, 4, (1L<<2), move, NULL);
	mlx_hook((all())->wind, 17, 0, end, NULL);
	mlx_loop((all())->mlx);
}