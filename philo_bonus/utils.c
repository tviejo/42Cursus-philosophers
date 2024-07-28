/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:01:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/28 22:08:04 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_message(t_philosopher *philo, char *message)
{
	sem_wait(philo->info->message);
	printf("%lld %d %s\n", current_time() - philo->info->start_time, philo->id,
		message);
	if (strcmp(message, "died") != 0)
		sem_post(philo->info->message);
}

void	cleanup(t_info *info)
{
	sem_close(info->forks);
	sem_close(info->message);
	sem_close(info->death);
	sem_close(info->lock);
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/death");
	sem_unlink("/lock");
}

void	terminate_simulation(t_philosopher *philosophers, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philosophers)
	{
		kill(philosophers[i].pid, SIGKILL);
		i++;
	}
}
