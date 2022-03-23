/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_activities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:50:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/23 04:31:11 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Thinking (Philosopher activity).
 * Print current timestamp
 *
 * @param philo: philosopher data
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_think(t_philosopher *philo)
{
	time_t			curr_timestamp;
	time_t			*begin_timestamp;
	unsigned int	philo_id;

	if (philo == NULL)
		return (FALSE);
	if (ft_get_timestamp(&curr_timestamp) == FALSE)
		return (FALSE);
	philo_id = philo->id;
	begin_timestamp = philo->philo_data->begin_timestamp;
	printf("%ld %u is thinking\n", curr_timestamp - *begin_timestamp, philo_id);
	return (TRUE);
}

/**
 * @brief Take a fork (Philosoper activity)
 * Lock a fork mutex & print message
 *
 * @param philo: philosopher data
 * @param fork_id: fork ID (IDentifier)
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_get_fork(t_philosopher *philo, unsigned int fork_id)
{
	int				lock_ret;
	time_t			*begin_timestamp;
	time_t			curr_timestamp;
	unsigned int	philo_id;
	pthread_mutex_t	*forks;

	if (philo == NULL)
		return (FALSE);
	forks = philo->philo_data->fork_mutexes;
	lock_ret = pthread_mutex_lock(&forks[fork_id]);
	if (lock_ret != 0)
	{
		ft_putendl_fd(E_MUTEX_LOCK, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		philo_id = philo->id;
		begin_timestamp = philo->philo_data->begin_timestamp;
		if (ft_get_timestamp(&curr_timestamp) == FALSE)
			return (FALSE);
		printf("%ld %u has taken a fork\n",
			curr_timestamp - *begin_timestamp, philo_id);
		return (TRUE);
	}
}

/**
 * @brief Eat (Philosopher activity)
 * Sleep for time_to_eat ms & print message
 *
 * @param philo: philosopher data
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_eat(t_philosopher *philo)
{
	time_t			*begin_timestamp;
	time_t			curr_timestamp;
	unsigned int	philo_id;
	unsigned int	time_to_eat;

	if (philo == NULL)
		return (FALSE);
	philo_id = philo->id;
	time_to_eat = philo->philo_data->philo_args->time_to_eat;
	begin_timestamp = philo->philo_data->begin_timestamp;
	if (ft_get_timestamp(&curr_timestamp) == FALSE)
		return (FALSE);
	printf("%ld %u is eating\n", curr_timestamp - *begin_timestamp, philo_id);
	if (usleep(time_to_eat) == -1)
		return (FALSE);
	else
		return (TRUE);
}

/**
 * @brief Release fork (Philosopher activity)
 * Unlock fork mutex
 *
 * @param philo: philosopher data
 * @param fork_id: fork ID (IDentifier)
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_release_fork(t_philosopher *philo, unsigned int fork_id)
{
	int				unlock_ret;
	pthread_mutex_t	*forks;

	if (philo == NULL)
		return (FALSE);
	forks = philo->philo_data->fork_mutexes;
	unlock_ret = pthread_mutex_unlock(&forks[fork_id]);
	if (unlock_ret != 0)
	{
		ft_putendl_fd(E_MUTEX_UNLOCK, STDERR_FILENO);
		return (FALSE);
	}
	else
		return (TRUE);
}

/**
 * @brief Sleep (Philosopher activity)
 * Sleep for time_to_sleep ms & print
 *
 * @param philo: philosopher data
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_sleep(t_philosopher *philo)
{
	unsigned int	philo_id;
	unsigned int	time_to_sleep;
	time_t			*begin_timestamp;
	time_t			curr_timestamp;

	if (philo == NULL)
		return (FALSE);
	philo_id = philo->id;
	time_to_sleep = philo->philo_data->philo_args->time_to_sleep;
	begin_timestamp = philo->philo_data->begin_timestamp;
	if (ft_get_timestamp(&curr_timestamp) == FALSE)
		return (FALSE);
	printf("%ld %u is sleeping\n", curr_timestamp - *begin_timestamp, philo_id);
	if (usleep(time_to_sleep) == -1)
		return (FALSE);
	else
		return (TRUE);
}
