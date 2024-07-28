/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:01:18 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/28 22:11:50 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philosopher *philo)
{
	sem_wait(philo->info->forks);
	print_message(philo, "has taken a fork");
	sem_wait(philo->info->forks);
	print_message(philo, "has taken a fork");
}

void	put_forks(t_philosopher *philo)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	eat(t_philosopher *philo)
{
	take_forks(philo);
	sem_wait(philo->info->lock);
	philo->last_meal = current_time();
	philo->times_eaten++;
	sem_post(philo->info->lock);
	print_message(philo, "is eating");
	custom_sleep_eating(philo->last_meal, philo->info->time_to_eat);
	put_forks(philo);
}

void	sleeping(t_philosopher *philo)
{
	long	timestamp;

	timestamp = current_time();
	print_message(philo, "is sleeping");
	custom_sleep_sleeping(timestamp, philo->info->time_to_sleep);
}

void	philosopher(t_philosopher *philo)
{
	pthread_t	death_checker;

	pthread_create(&death_checker, NULL, check_death, philo);
	while (1)
	{
		print_message(philo, "is thinking");
		eat(philo);
		if (philo->info->num_times_must_eat != -1
			&& philo->times_eaten >= philo->info->num_times_must_eat)
			exit(0);
		sleeping(philo);
	}
}
