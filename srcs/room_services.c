/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_services.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:25:45 by omercade          #+#    #+#             */
/*   Updated: 2021/11/04 19:49:31 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	doctor(t_philo *philo)
{
	if (philo->state == Finish)
		return (0);
	if ((get_time() - philo->last_meal) > philo->room->starve_time)
	{
		pthread_mutex_lock(&philo->room->megaphone);
		philo->room->control = Inactive;
		pthread_detach(philo->tid);
		philo->room->start_time = get_time() - philo->room->start_time;
		return (philo->id);
	}
	return (0);
}

int	chef(t_philo *philos, t_room *room)
{
	int	i;

	i = 0;
	while (i < room->cap)
	{
		if (philos[i].state != Finish)
			return (1);
		i++;
	}
	pthread_mutex_lock(&room->megaphone);
	room->control = Inactive;
	return (0);
}

void	room_services(t_room *room, t_philo *philos)
{
	int	i;
	int	ret;

	i = 0;
	while (room->control == Active)
	{
		ret = doctor(&philos[i]);
		if (!chef(philos, room) || ret != 0)
		{
			pthread_mutex_unlock(&room->megaphone);
			if (ret != 0)
				printf("%ld ms %d died.\n", room->start_time, ret);
			i = 0;
			while (i < room->cap)
				pthread_join(philos[i++].tid, NULL);
		}
		else
		{
			usleep(5);
			i = (i + 1) % room->cap;
		}
	}
	return ;
}
