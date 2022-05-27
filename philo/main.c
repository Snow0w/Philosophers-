#include "philo.h"

int	main(int argc, char ** argv)
{
	int	flag;
	pthread_t		*threads;

	if (!(argc == 5 || argc == 6))
		return (msg_correct_input());
	if (argc == 5)
		flag = 0;
	else
		flag = 1;
	threads = NULL;
	return (first_parse(argv, flag, threads));
} 
