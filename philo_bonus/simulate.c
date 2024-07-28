/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:01:21 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/28 22:08:21 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_simulation(t_info *info, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while (i < info->num_philosophers)
	{
		philosophers[i].pid = fork();
		if (philosophers[i].pid < 0)
		{
			terminate_simulation(philosophers, info);
			return ;
		}
		if (philosophers[i].pid == 0)
			philosopher(&philosophers[i]);
		i++;
	}
	if (waitpid(-1, NULL, 0) || sem_wait(info->death))
		terminate_simulation(philosophers, info);
}
