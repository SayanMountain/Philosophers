/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <pjeffere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:57:38 by pjeffere          #+#    #+#             */
/*   Updated: 2021/08/19 13:07:13 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	prepare_input_param(int argc, char **argv, t_philo *t)
{

	check_num_of_arg(argc);
	t->philo_num = ft_atoi (argv[1]);
		check_philo_num(t);
	t->common_time = ft_atoi (argv[2]);
		check_common_time(t);
	t->philo_eat = ft_atoi (argv[3]);
		check_philo_eat(t);
	t->philo_sleep = ft_atoi (argv[4]);
		check_philo_sleep(t);
	if (argc == 6)
		t->must_eat = ft_atoi(argv[5]);
	else
		t->must_eat = -1;
	t->mutex = malloc(sizeof (pthread_mutex_t) * t->philo_num);
	t->tred = malloc(sizeof (t_tred) * t->philo_num);
	return (0);
}

void	create_and_gave_mutex(t_philo *t)
{
	int	i;

	i = 0;
	while (i < t->philo_num)
	{
		pthread_mutex_init (&t->mutex[i], NULL);
		i++;
	}
	pthread_mutex_init (&t->message, NULL);
	i = 0;
	while (i < t->philo_num)
	{
		t->tred[i].philo_id = i + 1;
		t->tred[i].left = &t->mutex[i];
		if (i != t->philo_num - 1)
			t->tred[i].right = &t->mutex[i + 1];
		else
			t->tred[i].right = &t->mutex[0];
		i++;
	}
}

void	create_and_launch_threads(t_philo *t)
{
	int	i;

	i = 0;
	while (i < t->philo_num)
	{
		t->tred[i].table = t;
		i++;
	}
	i = 0;
	t->start_time = get_time();
	while (i < t->philo_num)
	{
		t->tred[i].start_time = t->start_time;
		t->tred[i].act_eat = t->must_eat;
		pthread_create (&t->tred[i].philo, NULL, &life, (void *) &t->tred[i]);
		i++;
	}
}

int	check_death_and_must_eat(t_philo *t)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < t->philo_num)
		{
			usleep (100);
			if (t->common_time <= \
			(get_time() - t->tred[i].start_time - t->tred[i].last_eat))
			{
				pthread_mutex_lock(&t->message);
				printf("Time: %lu  Philo %d is died\n", \
					   get_time() - t->start_time, t->tred->philo_id);
				pthread_mutex_unlock(&t->message);
				return (-1);
			}
			if (t->all_eat == t->philo_num)
			{
				printf("Все философы поели %d раз\n", t->must_eat);
				return (1);
			}
			i++;
		}
	}
}
