#include "philo.h"

int	*die_flag(void)
{
	static int	flag;

	return (&flag);
}

int	get_die_flag(t_input_data *data)
{
	int	flag;

	pthread_mutex_lock(&(data->flag_mut));
	flag = *die_flag;
	pthread_mutex_unlock(&(data->flag_mut));
	return (flag);
}

int	set_die_flag(t_input_data *data, int flag)
{
	pthread_mutex_lock(&(data->flag_mut));
	*die_flag = flag;
	pthread_mutex_unlock(&(data->flag_mut));
	return (flag);
}
