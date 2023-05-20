#include "chess.h"

void	load_alpha_num()
{
		printf("0\n");
	all.alpha_num[0] = image_creator("alpha/0.xpm");
		printf("1\n");
	all.alpha_num[1] = image_creator("alpha/1.xpm");
	all.alpha_num[2] = image_creator("alpha/2.xpm");
	all.alpha_num[3] = image_creator("alpha/3.xpm");
	all.alpha_num[4] = image_creator("alpha/4.xpm");
	all.alpha_num[5] = image_creator("alpha/5.xpm");
	all.alpha_num[6] = image_creator("alpha/6.xpm");
	all.alpha_num[7] = image_creator("alpha/7.xpm");
	printf("7\n");
	all.alpha_num[8] = image_creator("alpha/8.xpm");
	all.alpha_num[9] = image_creator("alpha/9.xpm");
	all.alpha_num[10] = image_creator("alpha/A.xpm");
	all.alpha_num[11] = image_creator("alpha/B.xpm");
	all.alpha_num[12] = image_creator("alpha/C.xpm");
	all.alpha_num[13] = image_creator("alpha/D.xpm");
	all.alpha_num[14] = image_creator("alpha/E.xpm");
	all.alpha_num[15] = image_creator("alpha/F.xpm");
	all.alpha_num[16] = image_creator("alpha/G.xpm");
	all.alpha_num[17] = image_creator("alpha/H.xpm");
	all.alpha_num[18] = image_creator("alpha/I.xpm");
	all.alpha_num[19] = image_creator("alpha/J.xpm");
	all.alpha_num[20] = image_creator("alpha/K.xpm");
	all.alpha_num[21] = image_creator("alpha/L.xpm");
	all.alpha_num[22] = image_creator("alpha/M.xpm");
	all.alpha_num[23] = image_creator("alpha/N.xpm");
	all.alpha_num[24] = image_creator("alpha/O.xpm");
	all.alpha_num[25] = image_creator("alpha/P.xpm");
	all.alpha_num[26] = image_creator("alpha/Q.xpm");
	all.alpha_num[27] = image_creator("alpha/R.xpm");
	all.alpha_num[28] = image_creator("alpha/S.xpm");
	all.alpha_num[29] = image_creator("alpha/T.xpm");
	all.alpha_num[30] = image_creator("alpha/U.xpm");
	all.alpha_num[31] = image_creator("alpha/V.xpm");
	all.alpha_num[32] = image_creator("alpha/W.xpm");
	all.alpha_num[33] = image_creator("alpha/X.xpm");
	all.alpha_num[34] = image_creator("alpha/Y.xpm");
	all.alpha_num[35] = image_creator("alpha/Z.xpm");
}

int	find_lowest_pixel(t_img	img)
{
	int	x;
	int	y = 0;
	int	lowest = 0;

	while (y < img.height)
	{
		x = 0;
		while (x < img.width)
		{
			if (get_color(img, x, y) == 0x00000000)
			{
				lowest = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (lowest);
}

int	find_leftmost_pixel(t_img img)
{
	int	x;
	int	y = 0;
	int	lowest = -1;

	while (y < img.height && lowest != 0)
	{
		x = 0;
		while (x < img.width)
		{
			if (get_color(img, x, y) == 0)
			{
				if (x < lowest || lowest == -1)
					lowest = x;
				break ;
			}
			x++;
		}
		y++;
	}
	return (lowest);
}

void	display_letter(int i, int j, t_img letter, int color, double size)
{
	int	x_start = find_leftmost_pixel(letter);
	int	y_end = find_lowest_pixel(letter);
	int	y = 0;
	int	x;
	int	w;
	int	h = 0;
	int	pixels = 1 / size;

	printf("%d\n", pixels);
	while (y <= y_end / pixels)
	{
		x = x_start;
		w = x_start;
		while (w <= letter.width)
		{
			if (get_color(letter, w, y_end - h) == 0)
				my_mlx_pixel_put(&(all.canva), x - x_start + i, j + (y_end / pixels) - y, color);
			x++;
			w += pixels;
		}
		y++;
		h += pixels;
	}
}
