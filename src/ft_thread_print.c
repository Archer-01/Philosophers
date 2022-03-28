/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 05:45:55 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/28 10:47:40 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Print appropriate message based on philosopher activity
 * (Helper function for ft_thread_print)
 *
 * @param activity: activity string
 * @param timestamp: current timestamp
 * @param philo_id: philosopher ID (IDentifier)
 */
static void	ft_print_appropriate_message(const char *activity, time_t timestamp,
	unsigned int philo_id)
{
	if (activity == NULL)
		return ;
	else if (ft_strcmp(activity, ACT_THINK) == 0)
		printf("%ld %u is thinking\n", timestamp, philo_id);
	else if (ft_strcmp(activity, ACT_FORK) == 0)
		printf("%ld %u has taken a fork\n", timestamp, philo_id);
	else if (ft_strcmp(activity, ACT_EAT) == 0)
		printf("%ld %u is eating\n", timestamp, philo_id);
	else if (ft_strcmp(activity, ACT_SLEEP) == 0)
		printf("%ld %u is sleeping\n", timestamp, philo_id);
	else
		ft_putendl_fd(E_INVAL_ACT, STDERR_FILENO);
}

/**
 * @brief Print thread activity
 *
 * @param activity: activity string
 * @param timestamp: current timestamp
 * @param philo_id: philosopher ID (IDentifier)
 * @param writing_mutex: writing_mutex
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_thread_print(const char *activity, time_t timestamp,
	unsigned int philo_id, pthread_mutex_t *writing_mutex)
{
	if (activity == NULL || writing_mutex == NULL)
		return (FALSE);
	if (ft_lock_mutex(writing_mutex) == FALSE)
		return (FALSE);
	if (ft_strcmp(activity, ACT_DEATH) == 0)
	{
		printf("%ld %u died\n", timestamp, philo_id);
		return (TRUE);
	}
	ft_print_appropriate_message(activity, timestamp, philo_id);
	if (ft_unlock_mutex(writing_mutex) == FALSE)
		return (FALSE);
	else
		return (TRUE);
}
