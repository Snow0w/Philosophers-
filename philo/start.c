/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:26:08 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_philo_threads(t_input_data *data, pthread_t *threads,
		pthread_t *garcon, pthread_t *finisher)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		if (pthread_join(threads[i], NULL))
			return (1);
		i++;
	}
	if (pthread_join(*garcon, NULL))
		return (1);
	if (data->mode)
		if (pthread_join(*finisher, NULL))
			return (1);
	return (0);
}

int	sub_threads_start(t_input_data *data, pthread_t *threads)
{
	pthread_t		garcon;
	pthread_t		finisher;

	if (pthread_create(&garcon, NULL, start_garcon, data))
		return (1);
	if (data->mode)
		if (pthread_create(&finisher, NULL, start_finisher, data))
			return (1);
	if (join_philo_threads(data, threads, &garcon, &finisher))
		return (1);
	return (0);
}

int	start_only_one_philo(t_thread_data *big_data,
		t_input_data *data, pthread_t *threads)
{
	if (pthread_create(&threads[0], NULL, only_one_logic, &big_data[0]))
	{
		destroy_all(data, big_data, threads);
		return (1);
	}
	if (sub_threads_start(data, threads))
		return (1);
	return (destroy_all(data, big_data, threads));
}

int	start_logic(t_input_data *data, pthread_t *threads)
{
	int				i;
	t_thread_data	*big_data;

	big_data = NULL;
	if (initialise_data(data, &big_data, threads))
		return (1);
	i = 0;
	gettimeofday(&(data->time), NULL);
	if (data->num == 1)
	{
		big_data[i].cnt = i;
		memset(&(data->last_meal[i]), get_timestamp(data->time), data->num);
		return (start_only_one_philo(big_data, data, threads));
	}
	while (i < data->num)
	{
		big_data[i].cnt = i;
		memset(&(data->last_meal[i]), get_timestamp(data->time), data->num);
		if (pthread_create(&threads[i], NULL, start_thread, &big_data[i]))
			return (1);
		i++;
	}
	if (sub_threads_start(data, threads))
		return (1);
	return (destroy_all(data, big_data, threads));
}

int	first_parse(char **argv, int mode, pthread_t *threads)
{
	t_input_data	data;

	data.num = ft_atoi(argv[1]);
	if (data.num < 1)
		return (msg_wrong_philo_num());
	data.die_time = ft_atoi(argv[2]);
	if (data.die_time < 1)
		return (msg_wrong_die_time());
	data.eat_time = ft_atoi(argv[3]);
	if (data.eat_time < 1)
		return (msg_wrong_eat_time());
	data.sleep_time = ft_atoi(argv[4]);
	if (data.sleep_time < 1)
		return (msg_wrong_sleep_time());
	if (mode)
	{
		data.must_eat = ft_atoi(argv[5]);
		if (data.must_eat < 1)
			return (msg_must_eat());
	}
	data.mode = mode;
	threads = malloc(sizeof(pthread_t) * data.num);
	if (!threads)
		return (1);
	return (start_logic(&data, threads));
}
