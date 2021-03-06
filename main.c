/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <pjeffere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:59:02 by pjeffere          #+#    #+#             */
/*   Updated: 2021/08/19 11:11:17 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <fcntl.h>
#include <signal.h>

void	*life(void *structure)
{
	t_tred	*t;

	t = (t_tred *)structure;
	pthread_detach(t->philo);
	t->last_eat = get_time() - t->start_time;
	while (1)
	{
		eat_meat(t);
		t->act_eat--;
		if (t->act_eat == 0)
		{
			t->table->all_eat += 1;
			break ;
		}
		dream_night(t);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	t;

	if (argc != 5 && argc != 6)
	{
		printf("Agrc must be 5 or 6, current value of argc is equal %d\n", argc);
		return (1);
	}
	prepare_input_param(argc, argv, &t);
	if (check_philo_must_eat(argc, &t))
		return (1);
	if (check_philo_core(&t))
		return (1);
	create_and_gave_mutex(&t);
	create_and_launch_threads(&t);
	check_death_and_must_eat(&t);
	return (0);
}
