#include "chess.h"

void	pieces_creator()
{
	bishop_creator('w', 2);
	bishop_creator('w', 5);
	bishop_creator('b', 2);
	bishop_creator('b', 5);
}

int	move(int button, int x, int y, void *a)
{
	printf("button: %d\nx: %d\n y: %d\n", button, x, y);
	return (0);
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
	mlx_loop((all())->mlx);
}