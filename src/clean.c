/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:19:30 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/13 16:59:57 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end(t_bag *b, int *c)
{
	pthread_mutex_lock(&(b->write));
	pthread_mutex_lock(&(b->mstate));
	b->state = 0;
	pthread_mutex_unlock(&(b->mstate));
	pthread_mutex_unlock(&(b->write));
	*c = 0;
}

int	join(t_bag *b)
{
	int			i;
	pthread_t	t;

	i = 0;
	while (i < b->nb_p)
	{
		t = b->p[i].t;
		pthread_join(t, NULL);
		i++;
	}
	return (0);
}

void	destroy_mutex(t_bag *b)
{
	int	i;

	i = 0;
	while (i < b->nb_p)
	{
		pthread_mutex_destroy(&(b->forks[i]));
		pthread_mutex_destroy(&(b->p[i].mp));
		i++;
	}
	pthread_mutex_destroy(&(b->write));
	pthread_mutex_destroy(&(b->mstate));
}
