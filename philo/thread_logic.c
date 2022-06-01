/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:26:08 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	odd_philo(t_thread_data *info)
{
	pthread_mutex_lock(&(info->data->mutexes[info->cnt]));
	fork_msg(info);
	pthread_mutex_lock(&(info->data->mutexes[(info->cnt + 1)
			% info->data->num]));
	fork_msg(info);
	pthread_mutex_lock(&(info->data->meal_mut[info->cnt]));
	info->data->last_meal[info->cnt] = get_timestamp(info->data->time);
	pthread_mutex_unlock(&(info->data->meal_mut[info->cnt]));
	eat_msg(info);
	ft_usleep(info->data->eat_time);
	pthread_mutex_unlock(&(info->data->mutexes[info->cnt]));
	pthread_mutex_unlock(&(info->data->mutexes[(info->cnt + 1)
			% info->data->num]));
	return (0);
}

int	even_philo(t_thread_data *info)
{
	pthread_mutex_lock(&(info->data->mutexes[(info->cnt + 1)
			% info->data->num]));
	fork_msg(info);
	pthread_mutex_lock(&(info->data->mutexes[info->cnt]));
	fork_msg(info);
	pthread_mutex_lock(&(info->data->meal_mut[info->cnt]));
	info->data->last_meal[info->cnt] = get_timestamp(info->data->time);
	pthread_mutex_unlock(&(info->data->meal_mut[info->cnt]));
	eat_msg(info);
	ft_usleep(info->data->eat_time);
	pthread_mutex_unlock(&(info->data->mutexes[info->cnt]));
	pthread_mutex_unlock(&(info->data->mutexes[(info->cnt + 1)
			% info->data->num]));
	return (0);
}

int	sleeping_process(t_thread_data *info)
{
	sleep_msg(info);
	ft_usleep(info->data->sleep_time);
	return (0);
}

void	check_must_eat(t_thread_data *info, int *flag, int *cnt)
{
	(*cnt)++;
	if (*cnt != info->data->must_eat)
		return ;
	*flag = 0;
	pthread_mutex_lock(&(info->data->finish_mut));
	(info->data->finish_cnt)++;
	pthread_mutex_unlock(&(info->data->finish_mut));
}

void	*start_thread(void *ptr)
{
	t_thread_data	*info;
	int				cnt;
	int				flag;

	info = (t_thread_data *) ptr;
	cnt = 0;
	flag = 1;
	while (!get_die_flag(info->data))
	{
		think_msg(info);
		if (info->cnt % 2 && !get_die_flag(info->data))
			odd_philo(info);
		else if (!get_die_flag(info->data))
			even_philo(info);
		if (info->data->mode && flag)
			check_must_eat(info, &flag, &cnt);
		if (!get_die_flag(info->data))
			sleeping_process(info);
	}
	return (NULL);
}
