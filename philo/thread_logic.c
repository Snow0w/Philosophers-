#include "philo.h"

void *start_thread(void *ptr)
{
	t_thread_data	*info;

	info = (t_thread_data *) ptr;
	printf("Hello, %d\n", info->cnt);
	return (NULL);
}
