/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 05:45:55 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/29 04:51:09 by hhamza           ###   ########.fr       */
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
 * @param philo: philosopher data
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_thread_print(const char *activity, time_t timestamp,
	t_philosopher *philo)
{
	time_t	curr_timestamp;

	if (activity == NULL || philo == NULL)
		return (FALSE);
	if (ft_lock_mutex(&philo->philo_data->writing_mutex) == FALSE)
		return (FALSE);
	if (ft_strcmp(activity, ACT_DEATH) == 0)
	{
		printf("%ld %u died\n", timestamp, philo->id);
		return (TRUE);
	}
	if (ft_strcmp(activity, ACT_EAT) == 0)
	{
		if (ft_get_timestamp(&curr_timestamp) == FALSE)
			return (FALSE);
		philo->last_eat_time = curr_timestamp;
	}
	ft_print_appropriate_message(activity, timestamp, philo->id);
	if (ft_unlock_mutex(&philo->philo_data->writing_mutex) == FALSE)
		return (FALSE);
	else
		return (TRUE);
}
