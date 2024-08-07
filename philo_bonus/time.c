/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:01:24 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/28 22:11:59 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	custom_sleep_eating(long time_last_meal, long time_to_eat)
{
	while (current_time() - time_last_meal < time_to_eat)
	{
		usleep(10);
	}
}

void	custom_sleep_sleeping(long timestamp, long time_to_sleep)
{
	while (current_time() - timestamp < time_to_sleep)
	{
		usleep(10);
	}
}
