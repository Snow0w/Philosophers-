#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct timeval	t_time;

typedef struct s_input_data
{
	int	num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
	int	mode;
}				t_input_data;

int		ft_atoi(const char *str);
int		msg_correct_input(void);
int		first_parse(char **argv, int mode);
int		get_timestamp(t_time start_time);
int		msg_wrong_philo_num(void);
int		msg_wrong_eat_time(void);
int		msg_wrong_die_time(void);
int		msg_wrong_sleep_time(void);
int		free_threads_only(pthread_t *threads);
#endif
