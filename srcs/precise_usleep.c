/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_usleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:31:44 by omercade          #+#    #+#             */
/*   Updated: 2021/11/01 17:00:15 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	precise_usleep(time_t timer)
{
	time_t	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start == timer)
			return ;
		usleep(200);
	}
	return ;
}
