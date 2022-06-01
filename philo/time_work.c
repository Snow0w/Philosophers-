/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:26:11 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_timestamp(t_time start_time)
{
	t_time		current_time;
	time_t		sec_diff;
	suseconds_t	mi_sec_diff;
	int			out;

	gettimeofday(&current_time, NULL);
	sec_diff = current_time.tv_sec - start_time.tv_sec;
	if (current_time.tv_usec >= start_time.tv_usec)
	{
		mi_sec_diff = current_time.tv_usec - start_time.tv_usec;
		out = (int) sec_diff * 1000000 + (int) mi_sec_diff;
		return (out / 1000);
	}
	mi_sec_diff = start_time.tv_usec - current_time.tv_usec;
	out = (int) sec_diff * 1000000 - (int) mi_sec_diff;
	return (out / 1000);
}

int	ft_usleep(int time)
{
	t_time	current_time;
	int		start;

	gettimeofday(&current_time, NULL);
	start = (int) current_time.tv_sec * 1000
		+ (int) current_time.tv_usec / 1000;
	usleep(time * 800);
	while ((int) current_time.tv_sec * 1000
		+ (int) current_time.tv_usec / 1000 - start < time)
	{
		gettimeofday(&current_time, NULL);
		usleep(200);
	}
	return (0);
}
