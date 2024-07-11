/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:58:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/11 10:18:20 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dead_philo(t_data *data)
{
	int				i;
	long			time;

	i = -1;
	while (++i < data->number_of_philo)
	{
		pthread_mutex_lock(&data->philo[i].is_not_eating_mutex);
		if (data->philo[i].is_not_eating == true)
		{
			pthread_mutex_unlock(&data->philo[i].is_not_eating_mutex);
			time = custom_time();
			pthread_mutex_lock(&data->philo[i].time_of_last_meal_mutex);
			if (time - data->philo[i].time_of_last_meal > data->time_to_die)
			{
				message(&data->philo[i], "died");
				mutex_end(&data->philo[i], true);
				pthread_mutex_unlock(&data->philo[i].time_of_last_meal_mutex);
				return (EXIT_FAILURE);
			}
			pthread_mutex_unlock(&data->philo[i].time_of_last_meal_mutex);
		}
		else
			pthread_mutex_unlock(&data->philo[i].is_not_eating_mutex);
	}
	return (EXIT_SUCCESS);
}

void	*living_philo(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (end_is_true_philo(philo) == false)
	{
		message(philo, "is thinking");
		if (end_is_true_philo(philo) == true)
			break ;
		eating(philo);
		if (end_is_true_philo(philo) == true)
			break ;
		sleeping(philo);
	}
	return (NULL);
}

void	check_end(t_data *data)
{
	while (end_is_true_data(data) == false)
	{
		if (everyone_ate(data) == true)
		{
			mutex_end(&data->philo[0], true);
		}
		dead_philo(data);
	}
}

int	philosophers(t_data *data)
{
	int	i;

	i = 0;
	init_time(data);
	while (i < data->number_of_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, &living_philo,
			&data->philo[i]);
		i++;
	}
	check_end(data);
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
