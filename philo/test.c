#include "philo.h"


void	*start(void *argv)
{
	printf("HHello from ChinaTown and NewYorkHello from ChinaTown and NewYorkHello from ChinaTown and NewYorkHello from ChinaTown and NewYorkHello from ChinaTown and NewYorkHello from ChinaTown and NewYorkHello from ChinaTown and NewYorkHello from ChinaTown and NewYorkello from ChinaTown and NewYork\n");
	return (NULL);
}
int	main(int argc, char **argv)
{
	t_time	time;
	pthread_t	t[2];

	pthread_create(&t[1], NULL, &start, NULL);
	pthread_create(&t[2], NULL, &start, NULL);
	gettimeofday(&time, NULL);
	printf("sec: %ld\nmicrosec: %d\n", time.tv_sec, time.tv_usec);
	usleep(1500000);
	printf("%d\n", get_timestamp(time));
	return (0);
}
