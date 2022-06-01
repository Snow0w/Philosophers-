/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:26:08 by omanie            #+#    #+#             */
/*   Updated: 2022/06/01 17:26:52 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>

typedef struct timeval	t_time;

typedef struct s_input_data
{
	int				num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				mode;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	mut;
	t_time			time;
	int				*last_meal;
	pthread_mutex_t	*meal_mut;
	pthread_mutex_t	flag_mut;
	pthread_mutex_t	finish_mut;
	int				finish_cnt;
}				t_input_data;

typedef struct s_thread_data
{
	t_input_data	*data;
	int				cnt;
}				t_thread_data;

int		ft_atoi(const char *str);

int		msg_correct_input(void);
int		msg_wrong_philo_num(void);
int		msg_wrong_eat_time(void);
int		msg_wrong_die_time(void);
int		msg_wrong_sleep_time(void);
int		msg_must_eat(void);

int		destroy_all(t_input_data *data, t_thread_data *big_data,
			pthread_t *threads);
int		free_threads_only(pthread_t *threads);
int		free_threads_mutexes(pthread_t *threads, pthread_mutex_t *mutexes);
int		free_thread_mut_data(pthread_t *threads, pthread_mutex_t *mutexes,
			t_thread_data *big_data);
int		free_destroy_threads_mutex(t_input_data *data, t_thread_data *big_data,
			pthread_t *threads, int i);
int		free_after_init(pthread_t *threads, t_thread_data *big_data);
int		free_first_layer(t_input_data *data, t_thread_data *big_data,
			pthread_t *threads, int i);
int		free_first_layer2(t_input_data *data, t_thread_data *big_data,
			pthread_t *threads, int i);
int		free_first_layer3(t_input_data *data, t_thread_data *big_data,
			pthread_t *threads, int i);
int		free_first_layer4(t_input_data *data, t_thread_data *big_data,
			pthread_t *threads, int i);

int		first_parse(char **argv, int mode, pthread_t *threads);

int		get_timestamp(t_time start_time);

int		*die_flag(void);
int		get_die_flag(t_input_data *data);
int		set_die_flag(t_input_data *data, int flag);

int		initialise_data(t_input_data *data, t_thread_data **big_data,
			pthread_t *threads);

int		ft_usleep(int time);

int		think_msg(t_thread_data *info);
int		fork_msg(t_thread_data *info);
int		die_msg(t_input_data *info, int cnt);
int		sleep_msg(t_thread_data *info);
int		eat_msg(t_thread_data *info);

void	*start_thread(void *ptr);
void	*only_one_logic(void *ptr);
void	*start_garcon(void *ptr);
void	*start_finisher(void *ptr);
#endif
