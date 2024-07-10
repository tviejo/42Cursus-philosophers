/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close .c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:57:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:06:15 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_close(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].time_of_last_meal_mutex);
		pthread_mutex_destroy(&data->philo[i].nbr_of_meals_mutex);
		pthread_mutex_destroy(&data->philo[i].is_not_eating_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->end_mutex);
	return (EXIT_SUCCESS);
}
