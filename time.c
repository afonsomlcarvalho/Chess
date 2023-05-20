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
	str[0] = '0' + all.time[color] / 1000 / 60 / 10;
	str[1] = '0' + (all.time[color] / 1000 / 60) % 10;
	str[2] = ':';
	str[3] = '0' + ((all.time[color] / 1000) % 60) / 10;
	str[4] = '0' + ((all.time[color] / 1000) % 60) % 10;
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
		all.time[all.turn] -= get_time() - all.start;
		all.start = get_time();
		timer = get_time() + 500;
	}
	if (get_time() > timer2)
	{
		t1 = convert_time(0);
		t2 = convert_time(1);
		printf("White time: %s\nBlack time: %s\n\n", t1, t2);
		timer2 = get_time() + 3000;
		free(t1);
		free(t2);
	}
	return (0);
}
