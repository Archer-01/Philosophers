/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:57:48 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/27 03:18:47 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Philosophers routine.
 *
 * @param arg: argument (t_philosopher *)
 * @return void*: On success this function never returns, on failure it returns
 * NULL
 */
void	*ft_philo_routine(void *arg)
{
	t_philosopher	*philo;
	size_t			fork_count;

	if (arg == NULL)
		return (NULL);
	philo = (t_philosopher *) arg;
	while (TRUE)
	{
		if (ft_think(philo) == FALSE)
			return (NULL);
		fork_count = philo->philo_data->philo_args->philo_count;
		if (ft_get_fork(philo, (size_t) philo->id - 1) == FALSE)
			return (NULL);
		if (ft_get_fork(philo, (size_t) philo->id % fork_count) == FALSE)
			return (NULL);
		if (ft_eat(philo) == FALSE)
			return (NULL);
		if (ft_release_fork(philo, (size_t) philo->id - 1) == FALSE)
			return (NULL);
		if (ft_release_fork(philo, (size_t) philo->id % fork_count) == FALSE)
			return (NULL);
		if (ft_sleep(philo) == FALSE)
			return (NULL);
	}
}
