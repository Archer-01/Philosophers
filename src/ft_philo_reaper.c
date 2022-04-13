/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_reaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:17:39 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/13 11:56:33 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Check if a philosopher is dead
 *
 * @param philo: philosopher object
 * @return t_bool: TRUE if philosopher is dead, FALSE otherwise
 */
static t_bool	ft_is_dead(t_philosopher *philo)
{
	time_t			curr_time;
	time_t			start;
	time_t			last_eat_time;
	unsigned int	time_to_die;

	if (philo == NULL)
	{
		return (FALSE);
	}
	else
	{
		if (ft_gettimeofday(&curr_time) == FALSE)
			return (FALSE);
		start = philo->philo_data->begin_time;
		last_eat_time = philo->last_eat_time;
		time_to_die = philo->philo_data->philo_args->time_to_die;
		if ((curr_time - start) - last_eat_time >= last_eat_time + time_to_die)
			return (TRUE);
		else
			return (FALSE);
	}
}

/**
 * @brief Check if a philosopher has eaten at leat min_eat_count times
 *
 * @param philo: philosopher object
 * @return t_bool: TRUE if philosopher ate at least min_eat_count times, FALSE
 * otherwise
 */
static t_bool	ft_check_min_eat_count(t_philosopher *philo)
{
	unsigned int	min_eat_count;

	if (philo == NULL)
	{
		return (FALSE);
	}
	min_eat_count = philo->philo_data->philo_args->min_eat_count;
	if (min_eat_count == 0)
	{
		return (FALSE);
	}
	if (philo->eat_count >= min_eat_count)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

/**
 * @brief Actions to the philospher dies (Helper function for ft_philo_reaper)
 *
 * @param philo: philosopher object
 * @return t_bool: FALSE on failure, exit process otherwise
 */
static t_bool	ft_a_philo_died(t_philosopher *philo)
{
	time_t	curr_time;
	time_t	begin_time;

	if (philo == NULL)
		return (FALSE);
	begin_time = philo->philo_data->begin_time;
	if (ft_gettimeofday(&curr_time) == FALSE)
		return (FALSE);
	if (ft_sem_wait(philo->philo_data->writing_sem) == FALSE)
		return (FALSE);
	printf("%ld %u died\n", curr_time - begin_time, philo->id);
	philo->is_dead = TRUE;
	ft_destroy_philo_data(philo->philo_data);
	free(philo);
	return (TRUE);
}

/**
 * @brief Philosopher reaper.
 * End process if a philosopher died or if a philosopher ate at leat
 * min_eat_count times
 *
 * @param philo: philosopher object
 * @return t_bool: FALSE if philosopher is still alive or has not ate
 * min_eat_count times yet, exit program otherwise
 */
t_bool	ft_philo_reaper(t_philosopher *philo)
{
	if (philo == NULL)
		return (FALSE);
	while (TRUE)
	{
		if (ft_is_dead(philo) == TRUE)
		{
			if (ft_a_philo_died(philo) == FALSE)
				return (FALSE);
			exit(EXIT_FAILURE);
		}
		else if (ft_check_min_eat_count(philo) == TRUE)
		{
			philo->is_dead = TRUE;
			ft_destroy_philo_data(philo->philo_data);
			free(philo);
			exit(EXIT_SUCCESS);
		}
	}
}
