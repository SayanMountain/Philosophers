/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeffere <pjeffere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:59:08 by pjeffere          #+#    #+#             */
/*   Updated: 2021/08/19 13:06:32 by pjeffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <pthread.h>
# include <sys/semaphore.h>
# include "sys/time.h"
# include <time.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_tred
{
	pthread_t			philo;
	int					act_eat;
	int					philo_id;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	struct s_philo		*table;
	unsigned long		start_time;
	unsigned long int	last_eat;
}						t_tred;

typedef struct s_philo
{
	pthread_mutex_t		message;
	pthread_mutex_t		*mutex;
	t_tred				*tred;
	int					philo_num;
	int					philo_eat;
	int					philo_sleep;
	int					must_eat;
	int					all_eat;
	unsigned long		current_time;
	unsigned long		start_time;
	unsigned long		common_time;
}						t_philo;

long long			get_ms(struct timeval old);
int					ft_atoi(char *str);
int					check_death_and_must_eat(t_philo *t);
void				create_and_gave_mutex(t_philo *t);
void				create_and_launch_threads(t_philo *t);
int					prepare_input_param(int argc, char **argv, t_philo *t);
void				*life(void *structure);
void				eat_meat(t_tred *t);
void				dream_night(t_tred *t);
void				my_sleep( unsigned long int time_period);
void				usleeper(long time, struct timeval now);
unsigned long int	get_time(void);

#endif
