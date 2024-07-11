/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:42:18 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/11 10:13:36 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	simu_one(t_data *data)
{
	message(&data->philo[0], "is thinking");
	message(&data->philo[0], "has taken a fork");
	usleep(data->time_to_die * 1000);
	message(&data->philo[0], "died");
}
