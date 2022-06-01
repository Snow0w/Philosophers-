/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:25:54 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*only_one_logic(void *ptr)
{
	t_thread_data	*info;

	info = (t_thread_data *) ptr;
	while (!get_die_flag(info->data))
	{
		think_msg(info);
		pthread_mutex_lock(&(info->data->mutexes[info->cnt]));
		fork_msg(info);
		pthread_mutex_unlock(&(info->data->mutexes[info->cnt]));
		ft_usleep(info->data->die_time + info->data->sleep_time);
	}
	return (NULL);
}
