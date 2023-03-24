#ifndef CHESS_H
# define CHESS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	char	*path;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_img;

typedef struct s_piece
{
	int		x;
	int		y;
	t_img	img;
	char	color;
	int		moves;
	void (*display)(struct s_piece *self);
	int	(*move)(struct s_piece *self, int x, int y);
	struct s_piece *next;
}				t_piece;

typedef struct	s_all
{
	void	*mlx;
	void	*wind;
	t_img	canva;
	t_piece	*pieces;
	int		selected;
	t_piece	*selected_piece;
}				t_all;

t_all	*all(void);
void	paint_floor();
void	add_piece(t_piece *to_add);
t_img	image_creator(char *path);
void	display_piece(t_piece *piece);
void	paint();
int		modulo(int x);
int		is_there_piece_diagonal(t_piece *piece, int x, int y);
int		is_there_piece_same_line(t_piece *piece, int x, int y);
int		is_piece(int x, int y, char color);

void	knight_creator(char color, int x);
void	bishop_creator(char color, int x);
void	queen_creator(char color, int x);
void	pawn_creator(char color, int x);
void	rook_creator(char color, int x);
void	king_creator(char color, int x);

#endif