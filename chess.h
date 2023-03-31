#ifndef CHESS_H
# define CHESS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
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
	int		color;
	int		moves;
	char	*name;
	int		value;
	void (*display)(struct s_piece *self);
	int	(*move)(struct s_piece *self, int x, int y, int flag);
	struct s_piece *next;
}				t_piece;

typedef struct	s_all
{
	void	*mlx;
	void	*wind;
	t_img	canva;
	t_piece	*pieces;
	int		selected;
	int		turn;
	int		en_passant;
	int		pawn;
	t_piece	*selected_piece;
	t_img	pawn_pieces[8];
}				t_all;

# define WHITE 0
# define BLACK 1

t_all	*all(void);
void	paint_floor();
void	add_piece(t_piece *to_add);
t_img	image_creator(char *path);
void	display_piece(t_piece *piece);
void	paint();
int		modulo(int x);
int		is_there_piece_diagonal(t_piece *piece, int x, int y, int flag);
int		is_there_piece_same_line(t_piece *piece, int x, int y, int flag);
int		is_piece(int x, int y, int color);
int		king_in_check(int color, int x, int y);
void	eat(int x, int y, int color);
void	check_castle(t_piece *king, int x, int y);
void	check_en_passant(t_piece *pawn, int x, int y);
void	check();
void	free_all();

void	knight_creator(int color, int x, int y);
void	bishop_creator(int color, int x, int y);
void	queen_creator(int color, int x, int y);
void	pawn_creator(int color, int x, int y);
void	rook_creator(int color, int x, int y);
void	king_creator(int color, int x, int y);

#endif