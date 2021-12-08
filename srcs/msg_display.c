/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:30:42 by omercade          #+#    #+#             */
/*   Updated: 2021/11/04 16:20:41 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_ndigit(int n)
{
	int	res;

	if (n <= 9 && n >= -9)
		return (1);
	res = 1;
	while (!(n <= 9 && n >= -9))
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		dig;
	char	*str;

	dig = ft_ndigit(n);
	if (n < 0)
		dig++;
	str = malloc(dig + 1);
	if (!str)
		return (NULL);
	str[dig] = '\0';
	while (!(n <= 9 && n >= -9))
	{
		if (n < 0)
			str[--dig] = (n % 10) * -1 + '0';
		else
			str[--dig] = (n % 10) + '0';
		n = n / 10;
	}
	if (n < 0)
		str[--dig] = (n % 10) * -1 + '0';
	else
		str[--dig] = (n % 10) + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}

void	msg_display(t_philo *philo, char *str)
{
	char	*time;
	char	*seat;

	pthread_mutex_lock(&philo->room->megaphone);
	if (philo->room->control == Active)
	{
		time = ft_itoa(get_time() - philo->room->start_time);
		seat = ft_itoa(philo->id);
		write(1, time, ft_strlen(time));
		write(1, " ms ", 4);
		write(1, seat, ft_strlen(seat));
		write(1, str, ft_strlen(str));
		free(time);
		free(seat);
	}
	pthread_mutex_unlock(&philo->room->megaphone);
	return ;
}
