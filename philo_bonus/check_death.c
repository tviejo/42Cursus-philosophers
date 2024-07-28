/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:01:06 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/28 22:07:19 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (1)
	{
		sem_wait(philo->info->lock);
		if ((current_time() - philo->last_meal) > philo->info->time_to_die)
		{
			sem_post(philo->info->death);
			print_message(philo, "died");
			exit(1);
		}
		sem_post(philo->info->lock);
		usleep(100);
	}
	return (NULL);
}
