/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_life_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <pjeffere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:07:22 by pjeffere          #+#    #+#             */
/*   Updated: 2021/08/19 11:07:23 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(const t_tred *t, char *msg)
{
	pthread_mutex_lock(&t->table->message);
	printf ("Time: %lu  Philo %d %s\n", \
								get_time() - t->start_time, t->philo_id, msg);
	if (t->table->common_time > (get_time() - t->start_time - t->last_eat))
		pthread_mutex_unlock(&t->table->message);
}

void	eat_meat(t_tred *t)
{
	if (t->philo_id % 2)
	{
		usleep (100);
		pthread_mutex_lock(t->left);
		print_msg(t, "is taken fork");
	}
	else
	{
		pthread_mutex_lock(t->right);
		print_msg(t, "is taken fork");
	}
	print_msg(t, "is eating");
	t->last_eat = get_time() - t->start_time;
	my_sleep(t->table->philo_eat);
	pthread_mutex_unlock(t->left);
	pthread_mutex_unlock(t->right);
}

void	dream_night(t_tred *t)
{
	print_msg(t, "is sleeping");
	my_sleep(t->table->philo_sleep);
	print_msg(t, "is thinking");
}
