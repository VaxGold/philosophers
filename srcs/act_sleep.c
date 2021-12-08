/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:20:42 by omercade          #+#    #+#             */
/*   Updated: 2021/11/01 17:36:45 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	act_sleep(t_philo *philo)
{
	msg_display(philo, " is sleeping...\n");
	precise_usleep(philo->room->sleep_time);
	return ;
}
