NAME = chess

COMPILER = cc -Wall -Werror -Wextra

SRCS = 	main.c \
		paint.c \
		utils.c \
		t_piece.c \
		free.c \
		castle.c \
		en_passant.c

SRCS_PCS =	bishop.c \
			knight.c \
			queen.c \
			pawn.c \
			rook.c \
			king.c

SRCS_PCS_F = $(addprefix Pieces/, $(SRCS_PCS))

OBJS = $(SRCS:.c=.o)
OBJSPCS = $(SRCS_PCS_F:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJSPCS)
	@$(COMPILER) $(OBJS) $(OBJSPCS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -f $(OBJS) $(OBJSPCS)

fclean: clean
	@rm -f $(NAME)

re: fclean all