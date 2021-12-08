/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:13:13 by omercade          #+#    #+#             */
/*   Updated: 2021/11/04 19:32:46 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	init_mutex(t_room *room)
{
	int	i;

	i = -1;
	while (++i < room->cap)
	{
		if (pthread_mutex_init(&room->spoon[i], NULL))
			return (0);
	}
	return (1);
}

int	awake(int narg, char **xarg, t_room *this)
{
	if (!(babelf_i(xarg[1], &this->cap) && babelf_t(xarg[2], &this->starve_time)
			&& babelf_t(xarg[3], &this->eat_time)
			&& babelf_t(xarg[4], &this->sleep_time)))
		return (0);
	if (narg == 6)
	{
		if (!babelf_i(xarg[5], &this->eat_limit))
			return (0);
	}
	else
		this->eat_limit = -1;
	this->control = Active;
	if (pthread_mutex_init(&this->megaphone, NULL))
		return (1);
	this->spoon = malloc(sizeof(pthread_mutex_t) * this->cap);
	if (!init_mutex(this))
		return (0);
	this->start_time = 0;
	if (!this->spoon)
		return (0);
	return (1);
}

void	init_philos(t_philo *philos, t_room *room)
{
	int	i;

	i = -1;
	while (++i < room->cap)
	{
		philos[i].room = room;
		philos[i].id = i + 1;
		philos[i].n_meals = 0;
		philos[i].last_meal = 0;
		philos[i].l_spoon = &room->spoon[i];
		philos[i].r_spoon = &room->spoon[(i + 1) % room->cap];
		philos[i].state = Existing;
	}
	return ;
}

int	start(t_philo *philos, t_room *room)
{
	int	i;

	init_philos(philos, room);
	i = -1;
	room->start_time = get_time();
	while (++i < room->cap)
	{
		if (pthread_create(&philos[i].tid,
				NULL, philosopher, (void *)&philos[i]))
			return (0);
	}
	return (1);
}

int	main(int narg, char **xarg)
{
	t_room	room;
	t_philo	*philos;

	if (narg != 6 && narg != 5)
		return (1);
	else
	{
		if (!awake(narg, xarg, &room))
			return (1);
		philos = malloc(sizeof(t_philo) * room.cap);
		if (!philos)
			return (1);
		memset(philos, 0, sizeof(t_philo) * room.cap);
		if (!start(philos, &room))
			return (1);
		usleep(100);
		room_services(&room, philos);
		free(philos);
		free(room.spoon);
	}
	return (0);
}
