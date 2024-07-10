/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:04:55 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:36:15 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define NB_MAX_PHILO 200

typedef struct s_philosopher
{
	pthread_t		thread;
	int				id;
	long int		*start_time;
	pthread_mutex_t	time_of_last_meal_mutex;
	long int		time_of_last_meal;
	pthread_mutex_t	nbr_of_meals_mutex;
	int				nbr_of_meals;
	pthread_mutex_t	is_not_eating_mutex;
	bool			is_not_eating;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*message;
	pthread_mutex_t	*end_mutex;
	bool			*end;
	int				time_to_eat;
	int				time_to_sleep;
}					t_philosopher;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_eat;
	long int		start_time;
	t_philosopher	philo[NB_MAX_PHILO];
	pthread_mutex_t	forks[NB_MAX_PHILO];
	pthread_mutex_t	message;
	pthread_mutex_t	end_mutex;
	bool			end;
}					t_data;

int					ft_atoi(const char *str);
int					init_data(t_data *data, int argc, char **argv);
int					init_philosophers(t_data *data);
int					philosophers(t_data *data);
int					ft_close(t_data *data);
int					ft_init(t_data *data, int argc, char **argv);
int					eating(void *philo);
int					sleeping(t_philosopher *philo);
int					message(t_philosopher *philo, char *msg);
void				*living_philo(void *philosopher);
int					dead_philo(t_data *data);
bool				everyone_ate(t_data *data);
bool				end_is_true_data(t_data *data);
bool				end_is_true_philo(t_philosopher *philo);
int					custom_sleep(t_philosopher *philo, long time);
long int			custom_time(void);
void				mutex_is_not_eating(t_philosopher *philo,
						bool is_not_eating);
void				mutex_nbr_of_meals(t_philosopher *philo);
void				mutex_end(t_philosopher *philo, bool end);
void				take_forks(t_philosopher *philo);
int					intput_check(int argc, char **argv);
void				simu_one(t_data *data);

#endif
