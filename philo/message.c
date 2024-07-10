/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:58:36 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:06:38 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	ft_strncmp(char *msg, char *cmp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (msg[i] != cmp[i])
			return (false);
		i++;
	}
	return (true);
}

int	message(t_philosopher *philo, char *msg)
{
	struct timeval	tv;

	pthread_mutex_lock(philo->message);
	pthread_mutex_lock(philo->end_mutex);
	if (*philo->end == true && ft_strncmp(msg, "died", 4) == false)
	{
		pthread_mutex_unlock(philo->message);
		pthread_mutex_unlock(philo->end_mutex);
		return (EXIT_FAILURE);
	}
	printf("%ld Philosopher %d %s\n", (custom_time() - *philo->start_time),
		philo->id, msg);
	pthread_mutex_unlock(philo->message);
	pthread_mutex_unlock(philo->end_mutex);
	return (EXIT_SUCCESS);
}
