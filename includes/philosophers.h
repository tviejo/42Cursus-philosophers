#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philosopher
{
	pthread_t		thread;
	int				id;
	bool			dead;
	int				time_of_last_meal;
	int				nbr_of_meals;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
    int             *time_to_die;
    int             *time_to_eat;
    int             *time_to_sleep;
}					t_philosopher;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_eat;
	bool			one_is_dead;
	int				start_time;
	t_philosopher	*philo;
    pthread_mutex_t *forks;
}					t_data;

int					ft_atoi(const char *str);
int					init_data(t_data *data, int argc, char **argv);
int					init_philosophers(t_data *data);
int					philosophers(t_data *data);
int					ft_close(t_data *data);
int                ft_init(t_data *data, int argc, char **argv);
void               *eating(void *philo_ptr);

#endif