/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:13:21 by omercade          #+#    #+#             */
/*   Updated: 2021/11/01 17:57:40 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef enum s_state {Existing, Finish}	t_state;
typedef enum s_control {Active, Inactive}	t_control;

typedef struct s_room
{
	t_control		control;
	time_t			start_time;
	time_t			starve_time;
	time_t			eat_time;
	time_t			sleep_time;
	int				eat_limit;
	int				cap;
	pthread_mutex_t	*spoon;
	pthread_mutex_t	megaphone;
}					t_room;

typedef struct s_philo
{
	int				id;
	int				n_meals;
	time_t			last_meal;
	pthread_mutex_t	*l_spoon;
	pthread_mutex_t	*r_spoon;
	t_state			state;
	pthread_t		tid;
	t_room			*room;
}					t_philo;

void	*philosopher(void *data);
void	room_services(t_room *room, t_philo *philos);

void	act_eat(t_philo *philo);
void	act_sleep(t_philo *philo);
void	act_think(t_philo *philo);

int		babelf_t(char *str, time_t *dest);
int		babelf_i(char *str, int *dest);
time_t	get_time(void);
void	precise_usleep(time_t timer);

void	msg_display(t_philo *philo, char *str);
#endif
