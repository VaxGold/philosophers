/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:20:35 by omercade          #+#    #+#             */
/*   Updated: 2021/11/01 17:36:24 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_spoon(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		usleep(50);
		pthread_mutex_lock(philo->r_spoon);
		msg_display(philo, " has taken a fork.\n");
		pthread_mutex_lock(philo->l_spoon);
		msg_display(philo, " has taken a fork.\n");
	}
	else
	{
		pthread_mutex_lock(philo->l_spoon);
		msg_display(philo, " has taken a fork.\n");
		pthread_mutex_lock(philo->r_spoon);
		msg_display(philo, " has taken a fork.\n");
	}
	return ;
}

void	leave_spoon(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_spoon);
	pthread_mutex_unlock(philo->l_spoon);
}

void	act_eat(t_philo *philo)
{
	take_spoon(philo);
	msg_display(philo, " is eating...\n");
	philo->last_meal = get_time();
	precise_usleep(philo->room->eat_time);
	philo->n_meals++;
	if (philo->room->eat_limit != -1
		&& philo->n_meals == philo->room->eat_limit)
		philo->state = Finish;
	leave_spoon(philo);
	return ;
}
