/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:26:08 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	think_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	if (!get_die_flag(info->data))
		printf("%d %d is thinking\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}

int	fork_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	if (!get_die_flag(info->data))
		printf("%d %d has taken a fork\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}

int	eat_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	if (!get_die_flag(info->data))
		printf("%d %d is eating\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}

int	sleep_msg(t_thread_data *info)
{
	int	time;

	time = get_timestamp(info->data->time);
	pthread_mutex_lock(&(info->data->mut));
	if (!get_die_flag(info->data))
		printf("%d %d is sleeping\n", time, info->cnt + 1);
	pthread_mutex_unlock(&(info->data->mut));
	return (0);
}

int	die_msg(t_input_data *data, int cnt)
{
	int	time;

	time = get_timestamp(data->time);
	pthread_mutex_lock(&(data->mut));
	printf("%d %d died\n", time, cnt + 1);
	pthread_mutex_unlock(&(data->mut));
	return (0);
}
