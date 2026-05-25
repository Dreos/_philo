/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel < lloisel@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:37:33 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/13 17:08:23 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (error("Wrong number of argument\n"), 0);
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (error("one argument is not a number\n"), 0);
		i++;
	}
	return (1);
}

int	check_value(int argc, char **argv)
{
	int	i;

	i = ft_atoi(argv[1]);
	if (i < 1 || i > MAXPHILO)
		return (error("Number of philo incorrect\n"), 0);
	if (argc == 6)
	{
		i = ft_atoi(argv[5]);
		if (i <= 0)
			return (0);
	}
	return (1);
}

int	check(int argc, char **argv)
{
	if (!check_arg(argc, argv))
		return (0);
	if (!check_value(argc, argv))
		return (0);
	return (1);
}
