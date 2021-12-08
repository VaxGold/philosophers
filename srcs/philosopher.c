/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:31:54 by omercade          #+#    #+#             */
/*   Updated: 2021/11/01 17:38:44 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_routine(t_philo *philo, void (*action)(t_philo *philo))
{
	if (philo->room->control == Active)
	{
		action(philo);
		return (1);
	}
	return (0);
}

void	*philosopher(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->last_meal = get_time();
	while (philo->room->control == Active)
	{
		if (!philo_routine(philo, &act_eat) || philo->state == Finish)
			return (NULL);
		if (!philo_routine(philo, &act_sleep))
			return (NULL);
		if (!philo_routine(philo, &act_think))
			return (NULL);
	}
	return (NULL);
}
