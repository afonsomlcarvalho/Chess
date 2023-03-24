#include "chess.h"

void	free_all()
{
	t_piece *temp;

	while((all())->pieces)
	{
		temp = (all())->pieces->next;
		mlx_destroy_image((all())->mlx, (all())->pieces->img.img);
		free((all())->pieces);
		(all())->pieces = temp;
	}
	mlx_destroy_image((all())->mlx, (all())->canva.img);
	mlx_destroy_window((all())->mlx, (all())->wind);
	mlx_destroy_display((all())->mlx);
	free((all())->mlx);
}