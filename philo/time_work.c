#include "philo.h"

int	get_timestamp(t_time start_time)
{
	t_time		current_time;
	time_t		sec_diff;
	suseconds_t	mi_sec_diff;
	int			out;

	gettimeofday(&current_time, NULL);
	sec_diff = current_time.tv_sec - start_time.tv_sec;
	if (current_time.tv_usec >= start_time.tv_usec)
	{
		mi_sec_diff = current_time.tv_usec - start_time.tv_usec;
		out = (int) sec_diff * 1000000 + (int) mi_sec_diff;
		return (out / 1000);
	}
	mi_sec_diff = start_time.tv_usec - current_time.tv_usec;
	out = (int) sec_diff * 1000000 - (int) mi_sec_diff;
	return (out / 1000);
}

int	ft_usleep(int time)
{
	usleep((useconds_t) (time * 1000));
	return (0);
}
