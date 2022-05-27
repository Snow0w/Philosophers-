#include "philo.h"

int	*die_flag(void)
{
	static int	flag;

	return (&flag);
}
