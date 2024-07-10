/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:59:00 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:06:49 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	custom_sleep(t_philosopher *philo, long time)
{
	int	i;

	i = 0;
	while (i < 10 && end_is_true_philo(philo) == false)
	{
		usleep(100 * time);
		i++;
	}
	return (EXIT_SUCCESS);
}
