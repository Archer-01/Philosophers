/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:12:27 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/12 07:51:27 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Create philosophers (Processes)
 *
 * @param philo_data: philosophers data
 * @return pid_t*: array of philosophers PIDs (Process IDs), NULL on failure
 */
pid_t	*ft_create_philosophers(t_philo_data *philo_data)
{
	unsigned int	philo_count;
	unsigned int	i;
	pid_t			*pids;

	if (philo_data == NULL)
		return (NULL);
	philo_count = philo_data->philo_args->philo_count;
	pids = ft_allocate(philo_count, sizeof(pid_t));
	if (pids == NULL)
		return (NULL);
	i = 0;
	while (i < philo_count)
	{
		pids[i] = ft_fork();
		if (pids[i] == -1)
		{
			ft_kill_philosophers(pids, 0, i);
			free(pids);
			return (NULL);
		}
		else if (pids[i] == 0)
			ft_philo_process(i + 1, philo_data);
		++i;
	}
	return (pids);
}

/**
 * @brief Wait for philosophers (processes) to finish execution.
 * If a process exits with failure all other processes are killed
 *
 * @param pids: PID (Process ID) list
 * @param count: PID (Process ID) count
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_wait_philosophers(pid_t *pids, size_t count)
{
	size_t	i;

	if (pids == NULL)
	{
		return (FALSE);
	}
	i = 0;
	while (i < count)
	{
		if (ft_waitpid(pids[i]) == FALSE)
		{
			ft_kill_philosophers(pids, i, count);
			return (FALSE);
		}
		++i;
	}
	return (TRUE);
}

/**
 * @brief Kill philosophers (process)
 *
 * @param pids: PID (Process ID) list
 * @param start: starting index on PID list
 * @param count: number of processes to kill starting from start index
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_kill_philosophers(pid_t *pids, size_t start, size_t count)
{
	size_t	i;

	if (pids == NULL)
	{
		return (FALSE);
	}
	i = start;
	while (i < count)
	{
		ft_kill(pids[i], SIGTERM);
		++i;
	}
	return (TRUE);
}
