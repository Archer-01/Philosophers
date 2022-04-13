/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:34:47 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/13 10:14:24 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Initialize philosopher (process)
 *
 * @param id: philosopher ID
 * @param philo_data: philosophers data (arguments, semaphores, ...)
 * @return t_philosopher*: philosopher object, NULL on failure
 */
static t_philosopher	*ft_init_philosopher(unsigned int id,
	t_philo_data *philo_data)
{
	t_philosopher	*philo;

	if (philo_data == NULL)
		return (NULL);
	philo = ft_allocate(1, sizeof(t_philosopher));
	if (philo == NULL)
		return (NULL);
	philo->id = id;
	philo->philo_data = philo_data;
	philo->last_eat_time = 0;
	philo->eat_count = 0;
	philo->is_dead = FALSE;
	return (philo);
}

/**
 * @brief Philosopher process (This function always exits)
 * Also free pid array since its no longer needed
 *
 * @param id: philosopher ID
 * @param philo_data: philosophers data (arguments, semaphores, ...)
 * @param pids: list of pids to be freed
 */
void	ft_philo_process(unsigned int id, t_philo_data *philo_data, pid_t *pids)
{
	t_philosopher	*philo;

	if (philo_data == NULL || pids == NULL)
		exit(EXIT_FAILURE);
	free(pids);
	philo = ft_init_philosopher(id, philo_data);
	if (philo == NULL)
	{
		ft_destroy_philo_data(philo_data);
		exit(EXIT_FAILURE);
	}
	if (ft_philo_thread(philo) == FALSE)
	{
		ft_destroy_philo_data(philo_data);
		free(philo);
		exit(EXIT_FAILURE);
	}
	ft_destroy_philo_data(philo_data);
	free(philo);
	exit(EXIT_SUCCESS);
}
