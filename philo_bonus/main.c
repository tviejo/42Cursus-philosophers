/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:01:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/28 22:15:07 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info			info;
	t_philosopher	*philosophers;

	if (argc != 5 && argc != 6)
	{
		printf("Incorrect argument: number_of_philosophers time_to_die ");
		printf("_eat time_to_sleep");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	if (check_args(argc, argv) == false)
		return (EXIT_FAILURE);
	if (init_info(&info, argc, argv))
		return (EXIT_FAILURE);
	philosophers = init_philosophers(&info);
	if (!philosophers)
		return (EXIT_FAILURE);
	start_simulation(&info, philosophers);
	free(philosophers);
	cleanup(&info);
	return (EXIT_SUCCESS);
}
