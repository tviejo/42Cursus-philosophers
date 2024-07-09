#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosopher
{
	pthread_t		thread;
	int				id;
	bool			dead;
	long int		time_of_last_meal;
	int				nbr_of_meals;
	int				nb_forks;
	bool			is_not_eating;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*message;
	long int		*start_time;
	int				*time_to_die;
	int				*time_to_eat;
	int				*time_to_sleep;
}					t_philosopher;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_eat;
	bool			one_is_dead;
	long int		start_time;
	t_philosopher	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
}					t_data;

int					ft_atoi(const char *str);
int					init_data(t_data *data, int argc, char **argv);
int					init_philosophers(t_data *data);
int					philosophers(t_data *data);
int					ft_close(t_data *data);
int					ft_init(t_data *data, int argc, char **argv);
int					eating(void *philo_ptr);
int					sleeping(t_philosopher *philo);
int					message(t_philosopher *philo, char *msg);

#endif