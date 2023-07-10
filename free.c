#include "chess.h"

void	free_all()
{
	t_piece *temp;
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image((all())->mlx, (all())->pawn_pieces[i].img);
		i++;
	}
	while((all())->pieces)
	{
		temp = (all())->pieces->next;
		mlx_destroy_image((all())->mlx, (all())->pieces->img.img);
		free((all())->pieces);
		(all())->pieces = temp;
	}
	while((all())->dead)
	{
		temp = (all())->dead->next;
		mlx_destroy_image((all())->mlx, (all())->dead->img.img);
		free((all())->dead);
		(all())->dead = temp;
	}
	mlx_destroy_image((all())->mlx, (all())->canva.img);
	mlx_destroy_window((all())->mlx, (all())->wind);
	mlx_destroy_display((all())->mlx);
	free((all())->mlx);
}
