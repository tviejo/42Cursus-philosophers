/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:58:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/07/10 16:06:23 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	cpt;
	int						sign;
	unsigned long long int	value;

	cpt = 0;
	value = 0;
	sign = 1;
	while ((str[cpt] == ' ' || (9 <= str[cpt] && str[cpt] <= 13)))
		cpt++;
	if (str[cpt] == '-' || str[cpt] == '+')
		if (str[cpt++] == '-')
			sign *= -1;
	while ('0' <= str[cpt] && str[cpt] <= '9')
	{
		if ((value * 10) + (str[cpt] - '0') > 1844674407370955161 && sign == 1)
			return (-1);
		else if ((value * 10) + (str[cpt] - '0') > 1844674407370955161
			&& sign == -1)
			return (0);
		value = (value * 10) + (str[cpt] - '0');
		cpt++;
	}
	return (value * sign);
}
