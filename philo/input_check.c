/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:04:34 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:06:30 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	intput_check(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > NB_MAX_PHILO)
	{
		printf("Bad NB of PHILO\n");
		return (EXIT_FAILURE);
	}
	if (ft_atoi(argv[2]) < 60)
	{
		printf("Bad time to die\n");
		return (EXIT_FAILURE);
	}
	if (ft_atoi(argv[3]) < 60)
	{
		printf("Bad time to eat\n");
		return (EXIT_FAILURE);
	}
	if (ft_atoi(argv[4]) < 60)
	{
		printf("Bad time to sleep\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
