/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:01:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/28 22:15:27 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philosopher
{
	int				id;
	int				times_eaten;
	long long		last_meal;
	struct s_info	*info;
	pid_t			pid;
}					t_philosopher;

typedef struct s_info
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;
	long long		start_time;
	sem_t			*forks;
	sem_t			*message;
	sem_t			*death;
	sem_t			*lock;
}					t_info;

long int			current_time(void);
void				print_message(t_philosopher *philo, char *message);
void				custom_sleep_eating(long time_last_meal, long time_to_eat);
void				custom_sleep_sleeping(long timestamp, long time_to_sleep);
void				cleanup(t_info *info);
void				terminate_simulation(t_philosopher *philosophers,
						t_info *info);
void				philosopher(t_philosopher *philo);
void				*check_death(void *philosopher);
int					init_info(t_info *info, int argc, char **argv);
t_philosopher		*init_philosophers(t_info *info);
void				start_simulation(t_info *info, t_philosopher *philosophers);
bool				check_args(int argc, char **argv);

#endif