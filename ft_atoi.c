/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <pjeffere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:11:52 by pjeffere          #+#    #+#             */
/*   Updated: 2021/08/19 11:11:53 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int					kudrin;
	unsigned long long	numero;

	numero = 0;
	kudrin = 1;
	while (*str == '\t' || *str == '\f' || *str == '\r' \
			|| *str == '\n' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		numero = numero * 10 + (*str++ - '0');
	if ((numero > 9223372036854775807) && (kudrin == 1))
		return (-1);
	if (numero > 9223372036854775807 && (kudrin == -1))
		return (0);
	return (numero * kudrin);
}
