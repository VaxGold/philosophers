/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_think.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:20:48 by omercade          #+#    #+#             */
/*   Updated: 2021/10/30 20:04:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	act_think(t_philo *philo)
{
	msg_display(philo, " is thinking...\n");
	usleep(50);
	return ;
}
