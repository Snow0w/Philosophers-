/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:25:31 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_all(t_input_data *data, t_thread_data *big_data, pthread_t *threads)
{
	int	i;

	free(threads);
	i = 0;
	while (i < data->num)
	{
		pthread_mutex_destroy(&(data->meal_mut[i]));
		pthread_mutex_destroy(&(data->mutexes[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->finish_mut));
	pthread_mutex_destroy(&(data->flag_mut));
	pthread_mutex_destroy(&(data->mut));
	free(big_data);
	free(data->meal_mut);
	free(data->last_meal);
	free(data->mutexes);
	return (0);
}
