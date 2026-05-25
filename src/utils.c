/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:39:39 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/13 15:05:29 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_number(char *s)
{
	if (*s == '-' || *s == '+' )
		s++;
	while (*s)
	{	
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

long long	ft_atoi(char *nptr)
{
	long long	sum;
	int			sign;

	sum = 0;
	sign = 1;
	while (*nptr && space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		sum = sum * 10;
		sum = sum + (*nptr - 48);
		nptr++;
	}	
	return (sum * sign);
}
