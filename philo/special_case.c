/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:42:18 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:42:27 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	simu_one(t_data *data)
{
	long	time;

	message(&data->philo[0], "is thinking");
	message(&data->philo[0], "has taken a fork");
	time = custom_time();
	while (end_is_true_data(data) == false)
	{
		if (data->philo[0].is_not_eating == true)
		{
			if (custom_time()
				- data->philo[0].time_of_last_meal > data->time_to_die)
			{
				message(&data->philo[0], "died");
				mutex_end(&data->philo[0], true);
				return ;
			}
		}
	}
}
