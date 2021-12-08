/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:33:24 by omercade          #+#    #+#             */
/*   Updated: 2021/11/01 17:37:16 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	get_time(void)
{
	struct timeval	result;

	gettimeofday(&result, NULL);
	return ((time_t)(result.tv_sec * 1000 + result.tv_usec / 1000));
}
