/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:58:07 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:22:15 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	everyone_ate(t_data *data)
{
	int	i;

	if (data->nbr_of_times_eat == -1)
		return (false);
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_lock(&data->philo[i].nbr_of_meals_mutex);
		if (data->philo[i].nbr_of_meals < data->nbr_of_times_eat)
		{
			pthread_mutex_unlock(&data->philo[i].nbr_of_meals_mutex);
			return (false);
		}
		pthread_mutex_unlock(&data->philo[i].nbr_of_meals_mutex);
		i++;
	}
	return (true);
}

int	sleeping(t_philosopher *philo)
{
	message(philo, "is sleeping");
	custom_sleep(philo, philo->time_to_sleep);
	return (EXIT_SUCCESS);
}

void	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		message(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		message(philo, "has taken a fork");
	}
}

int	eating(void *philo_ptr)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo_ptr;
	if (end_is_true_philo(philo) == true)
		return (EXIT_SUCCESS);
	take_forks(philo);
	mutex_is_not_eating(philo, false);
	message(philo, "is eating");
	custom_sleep(philo, philo->time_to_eat);
	philo->time_of_last_meal = custom_time();
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	mutex_nbr_of_meals(philo);
	mutex_is_not_eating(philo, true);
	return (EXIT_SUCCESS);
}
