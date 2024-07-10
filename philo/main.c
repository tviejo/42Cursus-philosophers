/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:58:29 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:06:34 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (ft_init(&data, argc, argv) == EXIT_FAILURE)
	{
		printf("Error: ft_init failed\n");
		return (EXIT_FAILURE);
	}
	if (philosophers(&data) == EXIT_FAILURE)
	{
		printf("Error: start_simulation failed\n");
		return (EXIT_FAILURE);
	}
	ft_close(&data);
	return (EXIT_SUCCESS);
}
