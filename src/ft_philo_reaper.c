/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_reaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 05:47:49 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/29 04:37:44 by hhamza           ###   ########.fr       */
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

	time_to_die = philo->philo_data->philo_args->time_to_die;
	last_eat_time = philo->last_eat_time;
	if ((curr_timestamp - last_eat_time) >= time_to_die)
		return (TRUE);
	else
		return (FALSE);
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
	time_t			curr_timestamp;

	if (philosophers == NULL || philo_count == 0)
		return (FALSE);
	philo_data = philosophers[0].philo_data;
	while (philo_data->did_someone_die == FALSE)
	{
		i = -1;
		while (++i < philo_count)
		{
			if (ft_get_timestamp(&curr_timestamp) == FALSE)
				return (FALSE);
			if (ft_this_philosopher_is_dead(&philosophers[i], curr_timestamp))
			{
				philo_data->did_someone_die = TRUE;
				ft_thread_print
					(ACT_DEATH, curr_timestamp - *philo_data->begin_timestamp,
						&philosophers[i]);
				break ;
			}
		}
	}
	return (TRUE);
}
