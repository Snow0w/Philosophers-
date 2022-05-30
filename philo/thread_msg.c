#include "philo.h"

int	think_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	printf("%d %d is thinking\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}

int	fork_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	printf("%d %d has taken a fork\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}

int	eat_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	printf("%d %d is eating\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}

int	sleep_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	printf("%d %d is sleeping\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}

int	die_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	printf("%d %d died\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}
