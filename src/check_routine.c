/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel < lloisel@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:08:54 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/13 13:20:39 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdead(t_philo *p)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(p->mp));
	if (p->eat_time + p->ttd < get_time())
	i = 1;
	pthread_mutex_unlock(&(p->mp));
	return (i);
}

int	full(t_philo *p)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(p->mp));
	if (p->nb_meal > 0)
	{
		i = p->nb_eat == p->nb_meal;
	}
	pthread_mutex_unlock(&(p->mp));
	return (i);
}

int	check_finish(t_philo *p)
{
	int	i;

	pthread_mutex_lock(&(p->b->mstate));
	i = p->b->state;
	pthread_mutex_unlock(&(p->b->mstate));
	return (i);
}

int	finish(t_philo *p)
{
	if (isdead(p))
		return (1);
	if (full(p))
		return (2);
	return (0);
}
