#include "philo.h"
//
//
////static int	check_arg(char *arg)
////{
////
////}
//
//{
//	int	i;
//
//	(void)argc;
//	i = -1;
//	while (*argv[++i])
//	{
//		if (!ft_isdigit(*(argv[i])))
//			return (0);
//	}
//	return (1);
//}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int print_pars_arg(void)
{
	printf("error in arg\n");
	exit(0);
}

int	check_philo_num(t_philo *t)
{
	if (t->philo_num < 1 || t->philo_num > 201 || ft_isdigit(t->philo_num))
		print_pars_arg();
	return 1;
}

int check_common_time(t_philo *t)
{
	if(t->common_time < 1)
		print_pars_arg();
	return 1;
}

int check_philo_sleep(t_philo *t)
{
	if(t->philo_sleep < 1 || ft_isdigit(t->philo_sleep))
		print_pars_arg();
	return 1;
}

int check_philo_eat(t_philo *t)
{
	if(t->philo_eat < 1 || ft_isdigit(t->philo_eat))
		print_pars_arg();
	return 1;
}

int	check_num_of_arg(int argc)
{
	if(argc != 5 && argc != 4)
	{
		printf("agrc must be 5 or 6, current value of argc is equal %d\n", argc);
//		exit(0);
		return -1;
	}
	return 1;
}

