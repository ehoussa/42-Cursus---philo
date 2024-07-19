/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:28 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/02 14:04:54 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(pthread_mutex_t *forks, int x)
{
	int	i;

	i = 0;
	while (i <= x)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_fill(t_inf *ph, char **av, int ac)
{
	int				i;
	pthread_mutex_t	*forks;
	int				index;

	i = 0;
	index = ft_atoi(av[1]);
	forks = malloc((index + 1) * sizeof(pthread_mutex_t));
	while (i < index)
	{
		ph[i].t_eat = ft_atoi(av[3]);
		ph[i].t_sleep = ft_atoi(av[4]);
		ph[i].forks = forks;
		ph[i].index = i;
		ph[i].nph = index;
		ph[i].ac = ac;
		if (ph[i].ac == 6)
			ph[i].m_eat = ft_atoi(av[5]);
		ph[i++].t_die = ft_atoi(av[2]);
	}
	if (ft_init_mutex(forks, index))
	{
		ft_free_all(ph, NULL);
		return (1);
	}
	return (0);
}

int	ft_check_die(t_inf *ph)
{
	int	i;
	int	j;

	while (1)
	{
		i = 0;
		j = 0;
		while (i < ph[i].nph)
		{
			if (ph[i].ac == 6 && ph[i].m_eat == 0)
				j++;
			if (j == ph[i].nph)
				return (0);
			if (ft_get_time() - ph[i].l_meal >= ph[i].t_die)
			{
				ft_print_msg(ph, "died");
				return (0);
			}
			i++;
		}
	}
	return (0);
}

void	ft_creat_philo(int ac, char **av)
{
	t_inf		*ph;
	pthread_t	*pt;
	int			i;

	ph = malloc(ft_atoi(av[1]) * sizeof(t_inf));
	if (ft_fill(ph, av, ac))
		return ;
	pt = malloc(ph[0].nph * sizeof(pthread_t));
	i = 0;
	ph[0].start = ft_get_time();
	while (i < ph[0].nph)
	{
		ph[i].start = ph[0].start;
		ph[i].l_meal = ph[0].start;
		if (pthread_create(&pt[i], NULL, &ft_routing, &ph[i]) != 0)
		{
			printf("Error\n");
			break ;
		}
		usleep(50);
		i++;
	}
	ft_check_die(ph);
	ft_free_all(ph, pt);
}

int	main(int ac, char **av)
{
	if (ft_error(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	if (ac == 6)
		if (ft_atoi(av[5]) == 0)
			return (0);
	if (ft_atoi(av[1]) == 0)
		return (0);
	ft_creat_philo(ac, av);
	return (0);
}
