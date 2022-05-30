#include "philo.h"

int	odd_philo(t_thread_data *info)
{
	pthread_mutex_lock(&(info->data->mutexes[info->cnt]));
	fork_msg(info);
	pthread_mutex_lock(&(info->data->mutexes[(info->cnt + 1) %
				info->data->num]));
	fork_msg(info);
	pthread_mutex_lock(&(info->data->meal_mut[info->cnt]));
	info->data->last_meal[info->cnt] = get_timestamp(info->data->time);
	pthread_mutex_unlock(&(info->data->meal_mut[info->cnt]));
	eat_msg(info);
	ft_usleep(info->data->eat_time);
	pthread_mutex_unlock(&(info->data->mutexes[info->cnt]));
	pthread_mutex_unlock(&(info->data->mutexes[(info->cnt + 1) %
				info->data->num]));
	return (0);
}

int	even_philo(t_thread_data *info)
{
	pthread_mutex_lock(&(info->data->mutexes[(info->cnt + 1) %
				info->data->num]));
	fork_msg(info);
	pthread_mutex_lock(&(info->data->mutexes[info->cnt]));
	fork_msg(info);
	pthread_mutex_lock(&(info->data->meal_mut[info->cnt]));
	info->data->last_meal[info->cnt] = get_timestamp(info->data->time);
	pthread_mutex_unlock(&(info->data->meal_mut[info->cnt]));
	eat_msg(info);
	ft_usleep(info->data->eat_time);
	pthread_mutex_unlock(&(info->data->mutexes[info->cnt]));
	pthread_mutex_unlock(&(info->data->mutexes[(info->cnt + 1) %
				info->data->num]));
	return (0);
}

int	sleeping_process(t_thread_data *info)
{
	sleep_msg(info);
	ft_usleep(info->data->sleep_time);
	return (0);
}

void *start_thread(void *ptr)
{
	t_thread_data	*info;
	int				flag;

	info = (t_thread_data *) ptr;
	flag = get_die_flag(info->data);
	while (!flag)
	{
		think_msg(info);
		if (info->cnt % 2)
			odd_philo(info);
		else
			even_philo(info);
		sleeping_process(info);
	}
	return (NULL);
}
