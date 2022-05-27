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
	int				num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				mode;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	mut;
	t_time			time;
	
}				t_input_data;

typedef struct	s_thread_data
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

int		free_threads_only(pthread_t *threads);
int		free_threads_mutexes(pthread_t *threads, pthread_mutex_t *mutexes);
int		free_thread_mut_data(pthread_t *threads, pthread_mutex_t *mutexes, t_thread_data *big_data);


int		first_parse(char **argv, int mode, pthread_t *threads);
void 	*start_thread(void *ptr);

int		get_timestamp(t_time start_time);

int		*die_flag(void);
#endif
