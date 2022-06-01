/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:25:54 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	msg_correct_input(void)
{
	printf("Please, write right input.\n");
	return (1);
}

int	msg_wrong_philo_num(void)
{
	printf("Number of philosophers can't be zero or less.\n");
	return (1);
}

int	msg_wrong_die_time(void)
{
	printf("Time to die can't be zero or less.\n");
	return (1);
}

int	msg_wrong_eat_time(void)
{
	printf("Time to eat can't be zero or less.\n");
	return (1);
}

int	msg_wrong_sleep_time(void)
{
	printf("Time to sleep can't be zero or less.\n");
	return (1);
}
