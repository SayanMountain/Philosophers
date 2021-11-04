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

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	print_pars_arg(t_errors err)
{
	if (err == ERROR_IN_ARGV_1)
		printf("Error in arg_1\n");
	if (err == ERROR_IN_ARGV_2)
		printf("Error in arg_2\n");
	if (err == ERROR_IN_ARGV_3)
		printf("Error in arg_3\n");
	if (err == ERROR_IN_ARGV_4)
		printf("Error in arg_4\n");
	if (err == ERROR_IN_ARGV_5)
		printf("Error in arg_5\n");
	return (err);
}

int	check_philo_must_eat(int argc, t_philo *t)
{
	if (argc == 6)
	{
		if (t->must_eat < 1 || ft_isdigit(t->philo_sleep))
		{
			print_pars_arg(ERROR_IN_ARGV_5);
			return (1);
		}
	}
	return (0);
}

int	check_philo_core(t_philo *t)
{
	if (t->philo_eat < 1)
	{
		print_pars_arg(ERROR_IN_ARGV_3);
		return (1);
	}
	if (t->philo_sleep < 1 || ft_isdigit(t->philo_sleep))
	{
		print_pars_arg(ERROR_IN_ARGV_4);
		return (1);
	}
	if (t->common_time < 1 || ft_isdigit(t->philo_sleep))
	{
		print_pars_arg(ERROR_IN_ARGV_2);
		return (1);
	}
	if (t->philo_num < 1 || ft_isdigit(t->philo_num))
	{
		print_pars_arg(ERROR_IN_ARGV_1);
		return (1);
	}
	return (0);
}
