/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:03:50 by omercade          #+#    #+#             */
/*   Updated: 2021/11/01 17:39:38 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	babelf_t(char *str, time_t *dest)
{
	int	i;

	*dest = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			*dest = *dest * 10 + str[i] - 48;
		else
			return (0);
		i++;
	}
	return (1);
}

int	babelf_i(char *str, int *dest)
{
	int	i;

	*dest = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			*dest = *dest * 10 + str[i] - 48;
		else
			return (0);
		i++;
	}
	return (1);
}
