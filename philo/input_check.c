/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:04:34 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:38:30 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	intput_check(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > NB_MAX_PHILO)
	{
		printf("Bad NB of PHILO\n");
		return (EXIT_FAILURE);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("time below 60ms\n");
		return (EXIT_FAILURE);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 0)
	{
		printf("Bad number of meals\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
