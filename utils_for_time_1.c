/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_time_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <pjeffere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:09:54 by pjeffere          #+#    #+#             */
/*   Updated: 2021/08/19 11:09:55 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(unsigned long int time_period)
{
	unsigned long int	new_time;

	new_time = get_time() + time_period;
	usleep ((time_period - 15) * 1000);
	while (get_time() < new_time)
	{
		usleep(300);
	}
}

unsigned long int	get_time(void)
{
	struct timeval				time;
	unsigned long int			ret;

	if (gettimeofday(&time, NULL))
		return (0);
	ret = time.tv_sec * 1000 + time.tv_usec * 0.001;
	return (ret);
}
