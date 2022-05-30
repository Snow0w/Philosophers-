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
	int				flag;
	int				time;

	info = (t_input_data *) ptr;
	flag = 1;
	while (flag)
	{
		i = 0;
		time = get_timestamp(info->time);
		while (flag && i < info->num)
		{
			if (check_die_time(i, info, time))
			{
				die_msg(info, i);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
