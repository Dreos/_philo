/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel < lloisel@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:03:07 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/13 17:17:39 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *p, char *s)
{
	pthread_mutex_lock(&(p->b->write));
	usleep(50);
	if (check_finish(p))
	{
		printf("%lld ", get_time() - p->b->s);
		printf("%d %s\n", p->nb, s);
	}
	pthread_mutex_unlock(&(p->b->write));
}

void	*exec(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	if (!(p->nb % 2))
		sleep_x(p->tte, p);
	while (check_finish(p) && p->b->nb_p > 1 && !full(p))
	{
		eat(p);
		pthread_mutex_lock(&(p->mp));
		p->nb_eat = p->nb_eat + 1;
		pthread_mutex_unlock(&(p->mp));
		slp(p);
		think(p);
	}
	return (NULL);
}

void	check_state(t_bag *b, int c, int count, int i)
{
	int	tmp;

	while (c)
	{
		i = 0;
		count = 0;
		while (c && i < b->nb_p)
		{
			tmp = finish(&(b->p[i]));
			if (tmp != 0)
			{
				if (tmp == 1)
				{
					end(b, &c);
					printf("%lld %d died\n", get_time() - b->s, b->p[i].nb);
				}
				else
					count++;
				if (c && count == b->nb_p)
					end(b, &c);
			}
			usleep(50);
			i++;
		}
	}
}

int	init_thread(t_bag *b)
{
	int	i;

	i = 0;
	while (i < b->nb_p)
	{
		if (pthread_create(&(b->p[i].t), NULL, exec, &(b->p[i])))
			return (1);
		i++;
	}
	check_state(b, 1, 0, 0);
	join(b);
	destroy_mutex(b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_bag	*b;

	if (check(argc, argv))
	{
		b = init_bag(argc, argv);
		if (init_thread(b))
		{
			printf("error thread");
			free(b);
			return (0);
		}
		else
			free(b);
	}
	return (0);
}
