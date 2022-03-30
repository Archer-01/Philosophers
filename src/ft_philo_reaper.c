/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_reaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 05:47:49 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/30 09:44:18 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Check if the philosopher provided as an argument is dead or not
 *
 * @param philo: philosopher to check
 * @param curr_timestamp: current timestamp
 * @return t_bool: TRUE if philosopher is dead, FALSE if not
 */
static t_bool	ft_this_philosopher_is_dead(t_philosopher *philo,
	time_t curr_timestamp)
{
	time_t	last_eat_time;
	time_t	time_to_die;
	time_t	start;

	time_to_die = philo->philo_data->philo_args->time_to_die;
	last_eat_time = philo->last_eat_time;
	start = *(philo->philo_data->begin_timestamp);
	if ((curr_timestamp - start) - last_eat_time >= time_to_die + last_eat_time)
		return (TRUE);
	else
		return (FALSE);
}

/**
 * @brief Check if philosoper is dead (Helper function for ft_philo_reaper)
 *
 * @param philo: philosopher to check
 * @return t_bool: TRUE if philosopher is dead, FALSE otherwise
 */
static t_bool	ft_check_philo_death(t_philosopher *philo)
{
	t_philo_data	*philo_data;
	time_t			curr_timestamp;

	philo_data = philo->philo_data;
	if (ft_get_timestamp(&curr_timestamp) == FALSE)
		return (FALSE);
	if (ft_this_philosopher_is_dead(philo, curr_timestamp) == TRUE)
	{
		philo_data->did_someone_die = TRUE;
		ft_thread_print
			(ACT_DEATH, curr_timestamp - *philo_data->begin_timestamp, philo);
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Check if all philosophers acheived the minimum eat count
 *
 * @param philosophers: philosophers array
 * @param philo_count: philosophers count
 * @return t_bool: TRUE if all philo acheived the min_eat_count, FALSE otherwise
 */
static t_bool	ft_check_philo_min_eat_count(t_philosopher *philosophers,
	size_t philo_count)
{
	unsigned int	min_eat_count;
	size_t			i;

	min_eat_count = philosophers[0].philo_data->philo_args->min_eat_count;
	if (min_eat_count == 0)
		return (FALSE);
	i = 0;
	while (i < philo_count)
	{
		if (philosophers[i].eat_count < min_eat_count)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/**
 * @brief Philosopher reaper.
 * End program if a philospher died
 *
 * @param philosophers: philosophers array
 * @param philo_count: philosophers count
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_philo_reaper(t_philosopher *philosophers, size_t philo_count)
{
	t_philo_data	*philo_data;
	size_t			i;

	if (philosophers == NULL || philo_count == 0)
		return (FALSE);
	philo_data = philosophers[0].philo_data;
	while (philo_data->did_someone_die == FALSE)
	{
		i = -1;
		while (++i < philo_count)
		{
			if (ft_check_philo_death(&philosophers[i]) == TRUE)
				return (TRUE);
		}
		if (ft_check_philo_min_eat_count(philosophers, philo_count) == TRUE)
		{
			philo_data->did_someone_die = TRUE;
			if (ft_lock_mutex(&philo_data->writing_mutex) == FALSE)
				return (FALSE);
			break ;
		}
	}
	return (TRUE);
}
