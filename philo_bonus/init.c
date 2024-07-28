/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:00:52 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/28 22:18:03 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	check_args(int argc, char **argv)
{
	if (atoi(argv[1]) < 1)
	{
		printf("Incorrect argument: number_of_philo must be at least 1\n");
		return (false);
	}
	if (atoi(argv[2]) < 60 || atoi(argv[3]) < 60 || atoi(argv[4]) < 60)
	{
		printf("Incorrect argument: time_to_die, time_to_eat and ");
		printf("time_to_sleep must be at least 60\n");
		return (false);
	}
	if (argc == 6 && atoi(argv[5]) < 1)
	{
		printf("Incorrect argument: number_of_times_each_philosopher_must_eat");
		printf("must be at least 1\n");
		return (false);
	}
	return (true);
}

int	init_info(t_info *info, int argc, char **argv)
{
	info->num_philosophers = atoi(argv[1]);
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		info->num_times_must_eat = atoi(argv[5]);
	else
		info->num_times_must_eat = -1;
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/death");
	sem_unlink("/all_eaten");
	sem_unlink("/lock");
	info->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644,
			info->num_philosophers);
	info->message = sem_open("/message", O_CREAT | O_EXCL, 0644, 1);
	info->death = sem_open("/death", O_CREAT | O_EXCL, 0644, 0);
	info->lock = sem_open("/lock", O_CREAT | O_EXCL, 0644, 1);
	if (info->forks == SEM_FAILED || info->message == SEM_FAILED
		|| info->death == SEM_FAILED)
		return (1);
	info->start_time = current_time();
	return (0);
}

t_philosopher	*init_philosophers(t_info *info)
{
	t_philosopher		*philosophers;
	int					i;

	philosophers = malloc(sizeof(t_philosopher) * info->num_philosophers);
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < info->num_philosophers)
	{
		philosophers[i].id = i + 1;
		philosophers[i].times_eaten = 0;
		philosophers[i].last_meal = info->start_time;
		philosophers[i].info = info;
		i++;
	}
	return (philosophers);
}
