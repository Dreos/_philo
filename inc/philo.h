/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel < lloisel@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:08:50 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/13 16:50:05 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define MAXPHILO 241
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_mutex_t	mp;
	struct s_bag	*b;
	pthread_t		t;
	long long		eat_time;
	long long		ttd;
	long long		tts;
	long long		tte;
	long long		ttt;
	int				nb;
	int				nb_eat;
	int				nb_meal;
	int				left;
	int				right;	
}			t_philo;

typedef struct s_bag
{
	pthread_mutex_t	write;
	pthread_mutex_t	mstate;
	pthread_mutex_t	forks[MAXPHILO];
	t_philo			p[MAXPHILO];
	long long		s;
	long long		ttd;
	long long		tts;
	long long		tte;
	long long		ttt;
	int				nb_p;
	int				state;
	int				nb_eat;	
}		t_bag;

void		end(t_bag *b, int *c);
void		destroy_mutex(t_bag *b);
void		print_action(t_philo *p, char *s);
void		eat(t_philo *p);
void		slp(t_philo *p);
void		think(t_philo *p);
void		error(char *s);
void		sleep_x(long long time, t_philo *p);
t_bag		*init_bag(int argc, char **argv);
long long	t_diff(long long first, long long second);
long long	get_time(void);
long long	ft_atoi(char *nptr);
int			check_arg(int argc, char **argv);
int			full(t_philo *p);
int			finish(t_philo *p);
int			is_number(char *s);
int			check_finish(t_philo *p);
int			join(t_bag *b);
int			check(int argc, char **argv);	
#endif
