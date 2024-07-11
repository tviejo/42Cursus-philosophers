/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:59:08 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/11 10:22:43 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_time(t_data *data)
{
	int	i;

	data->start_time = custom_time();
	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].start_time = &data->start_time;
		data->philo[i].time_of_last_meal = data->start_time;
		i++;
	}
}

long int	custom_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	custom_sleep_eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->time_of_last_meal_mutex);
	while (custom_time() - philo->time_of_last_meal < philo->time_to_eat)
	{
		usleep(10);
	}
	pthread_mutex_unlock(&philo->time_of_last_meal_mutex);
}

void	custom_sleep_sleeping(t_philosopher *philo, long int time)
{
	while (custom_time() - time < philo->time_to_sleep)
	{
		usleep(10);
	}
}
