#include "chess.h"

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);	
}

char	*convert_time(int color)
{
	char	*str;

	str = malloc(6);
	str[0] = '0' + (all())->time[color] / 1000 / 60 / 10;
	str[1] = '0' + ((all())->time[color] / 1000 / 60) % 10;
	str[2] = ':';
	str[3] = '0' + (((all())->time[color] / 1000) % 60) / 10;
	str[4] = '0' + (((all())->time[color] / 1000) % 60) % 10;
	str[5] = 0;
	return (str);
}

int	update_time(void *a)
{
	static time_t	timer;
	static time_t	timer2;
	char	*t1;
	char	*t2;

	if (get_time() > timer)
	{
		(all())->time[(all())->turn] -= get_time() - (all())->start;
		(all())->start = get_time();
		t1 = convert_time(0);
		t2 = convert_time(1);
		mlx_put_image_to_window((all())->mlx, (all())->wind, (all())->canva.img, 0, 0);
		mlx_string_put((all())->mlx, (all())->wind, 50, 50, 0xffffffff, t1);
		mlx_string_put((all())->mlx, (all())->wind, 50, 150, 0x00000000, t2);
		timer = get_time() + 500;
		free(t1);
		free(t2);
	}
}
