/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garcon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:25:48 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_die_time(int i, t_input_data *data, int time)
{
	int	last;

	pthread_mutex_lock(&(data->meal_mut[i]));
	last = data->last_meal[i];
	pthread_mutex_unlock(&(data->meal_mut[i]));
	if ((time - last) > data->die_time)
	{
		set_die_flag(data, 1);
		return (1);
	}
	return (0);
}

void	*start_garcon(void *ptr)
{
	t_input_data	*info;
	int				i;
	int				time;

	info = (t_input_data *) ptr;
	while (!(get_die_flag(info)))
	{
		i = 0;
		time = get_timestamp(info->time);
		while (!(get_die_flag(info)) && i < info->num)
		{
			if (check_die_time(i, info, time))
			{
				die_msg(info, i);
				return (NULL);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

void	*start_finisher(void *ptr)
{
	t_input_data	*info;
	int				finish_cnt;

	info = (t_input_data *) ptr;
	while (!(get_die_flag(info)))
	{
		pthread_mutex_lock(&(info->finish_mut));
		finish_cnt = info->finish_cnt;
		pthread_mutex_unlock(&(info->finish_mut));
		if (finish_cnt == info->num)
		{
			set_die_flag(info, 1);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
