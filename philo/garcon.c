#include "philo.h"

void	*start_garcon(void *ptr)
{
	t_input_data	*info;
	int				i;
	int				flag;
	int				time;

	info = (t_input_data *) ptr;
	flag = 1;
	while (flag)
	{
		i = 0;
		time = get_timestamp(info->time);
		while (i < info->num)
		{
			i++;
		}
	}
	return (NULL);
}
