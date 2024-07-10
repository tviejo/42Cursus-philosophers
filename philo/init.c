/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:58:22 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:06:27 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_data(t_data *data, int argc, char **argv)
{
	struct timeval	tv;

	data->start_time = custom_time();
	if (intput_check(argc, argv) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_of_times_eat = ft_atoi(argv[5]);
	else
		data->nbr_of_times_eat = -1;
	data->end = false;
	return (EXIT_SUCCESS);
}

int	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].start_time = &data->start_time;
		data->philo[i].id = i + 1;
		data->philo[i].time_of_last_meal = data->start_time;
		data->philo[i].nbr_of_meals = 0;
		data->philo[i].is_not_eating = true;
		data->philo[i].end = &data->end;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		pthread_mutex_init(&data->philo[i].time_of_last_meal_mutex, NULL);
		pthread_mutex_init(&data->philo[i].nbr_of_meals_mutex, NULL);
		pthread_mutex_init(&data->philo[i].is_not_eating_mutex, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->end_mutex, NULL);
	while (i < data->number_of_philo)
	{
		data->philo[i].end_mutex = &data->end_mutex;
		i++;
	}
	i = 0;
	pthread_mutex_init(&data->message, NULL);
	while (i < data->number_of_philo)
	{
		data->philo[i].message = &data->message;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].left_fork = &data->forks[i - 1];
		data->philo[i].right_fork = &data->forks[i];
		i++;
	}
	data->philo[0].left_fork = &data->forks[data->number_of_philo - 1];
	return (EXIT_SUCCESS);
}

int	ft_init(t_data *data, int argc, char **argv)
{
	if (init_data(data, argc, argv))
	{
		printf("Error: init_data failed\n");
		return (EXIT_FAILURE);
	}
	if (init_philosophers(data))
	{
		printf("Error: init_philosophers failed\n");
		return (EXIT_FAILURE);
	}
	if (init_fork(data))
	{
		printf("Error: fork failed\n");
		return (EXIT_FAILURE);
	}
	if (init_mutex(data))
	{
		printf("Error: mutex failed\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
