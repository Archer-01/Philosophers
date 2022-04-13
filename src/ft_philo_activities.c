/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_activities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:15:47 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/13 09:41:31 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Thinking (Philosopher activity)
 *
 * @param philo: philosopher object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_think(t_philosopher *philo)
{
	time_t	curr_time;
	time_t	begin_time;

	if (philo == NULL)
	{
		return (FALSE);
	}
	if (ft_gettimeofday(&curr_time) == FALSE)
	{
		return (FALSE);
	}
	begin_time = philo->philo_data->begin_time;
	if (ft_sem_wait(philo->philo_data->writing_sem) == FALSE)
	{
		return (FALSE);
	}
	printf("%ld %u is thinking\n", curr_time - begin_time, philo->id);
	if (ft_sem_post(philo->philo_data->writing_sem) == FALSE)
	{
		return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief Taking a fork (Philosopher activity)
 *
 * @param philo: philosopher object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_get_fork(t_philosopher *philo)
{
	time_t	curr_time;
	time_t	begin_time;
	sem_t	*fork_sem;

	if (philo == NULL)
		return (FALSE);
	fork_sem = philo->philo_data->fork_sem;
	if (ft_sem_wait(fork_sem) == FALSE)
		return (FALSE);
	else
	{
		begin_time = philo->philo_data->begin_time;
		if (ft_gettimeofday(&curr_time) == FALSE)
			return (FALSE);
		if (ft_sem_wait(philo->philo_data->writing_sem) == FALSE)
			return (FALSE);
		printf("%ld %u has taken a fork\n", curr_time - begin_time, philo->id);
		if (ft_sem_post(philo->philo_data->writing_sem) == FALSE)
			return (FALSE);
		return (TRUE);
	}
}

/**
 * @brief Eating (Philosopher activity)
 *
 * @param philo: philosopher object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_eat(t_philosopher *philo)
{
	time_t			begin_time;
	time_t			curr_time;
	unsigned int	time_to_eat;

	if (philo == NULL)
		return (FALSE);
	time_to_eat = philo->philo_data->philo_args->time_to_eat;
	begin_time = philo->philo_data->begin_time;
	if (ft_gettimeofday(&curr_time) == FALSE)
		return (FALSE);
	if (ft_sem_wait(philo->philo_data->writing_sem) == FALSE)
		return (FALSE);
	printf("%ld %u is eating\n", curr_time - begin_time, philo->id);
	philo->last_eat_time = curr_time - begin_time;
	if (ft_sem_post(philo->philo_data->writing_sem) == FALSE)
		return (FALSE);
	if (ft_usleep(time_to_eat * 1000) == FALSE)
		return (FALSE);
	else
	{
		++(philo->eat_count);
		return (TRUE);
	}
}

/**
 * @brief Releasing a fork (Philosopher activity)
 *
 * @param philo: philosopher object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_release_fork(t_philosopher *philo)
{
	sem_t	*fork_sem;

	if (philo == NULL)
		return (FALSE);
	fork_sem = philo->philo_data->fork_sem;
	if (ft_sem_post(fork_sem) == FALSE)
	{
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}

/**
 * @brief Sleeping (Philosopher activity)
 *
 * @param philo: philosopher object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_sleep(t_philosopher *philo)
{
	time_t			curr_time;
	time_t			begin_time;
	unsigned int	time_to_sleep;

	if (philo == NULL)
		return (FALSE);
	time_to_sleep = philo->philo_data->philo_args->time_to_sleep;
	begin_time = philo->philo_data->begin_time;
	if (ft_gettimeofday(&curr_time) == FALSE)
		return (FALSE);
	if (ft_sem_wait(philo->philo_data->writing_sem) == FALSE)
		return (FALSE);
	printf("%ld %u is sleeping\n", curr_time - begin_time, philo->id);
	if (ft_sem_post(philo->philo_data->writing_sem) == FALSE)
		return (FALSE);
	if (ft_usleep(time_to_sleep * 1000) == FALSE)
		return (FALSE);
	return (TRUE);
}
