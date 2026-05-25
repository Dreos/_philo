/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel < lloisel@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:04:49 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/13 17:00:36 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	choose_fork(t_philo *p, int i)
{
	if (((p->nb + i) % 2))
		return (p->left);
	return (p->right);
}

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(&(p->b->forks[choose_fork(p, 1)]));
	print_action(p, "has taken a fork ");
	pthread_mutex_lock(&(p->b->forks[choose_fork(p, 0)]));
	print_action(p, "has taken a fork");
}

void	eat(t_philo *p)
{
	if (full(p))
		return ;
	take_forks(p);
	pthread_mutex_lock(&(p->mp));
	p->eat_time = get_time();
	pthread_mutex_unlock(&(p->mp));
	print_action(p, "is eating");
	sleep_x(p->tte, p);
	pthread_mutex_unlock(&(p->b->forks[p->left]));
	pthread_mutex_unlock(&(p->b->forks[p->right]));
}

void	slp(t_philo *p)
{
	if (full(p))
		return ;
	print_action(p, "is sleeping");
	sleep_x(p->b->tts, p);
}

void	think(t_philo *p)
{
	if (full(p))
		return ;
	print_action(p, "is thinking");
	sleep_x(p->ttt, p);
}
