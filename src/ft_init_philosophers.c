/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:23:07 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/30 06:59:10 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Create thread using routine & arg as an argument to routine
 *
 * @param thread: thread address
 * @param routine: routine to use for the new thread
 * @param arg: argument to pass to the routine function
 * @return t_bool: TRUE on success, FALSE otherwise
 */
static t_bool	ft_create_thread(pthread_t *thread, t_routine routine,
	void *arg)
{
	int	ret;

	if (thread == NULL || routine == NULL)
		return (FALSE);
	ret = pthread_create(thread, NULL, routine, arg);
	if (ret != 0)
	{
		ft_putendl_fd(E_THREAD_CREAT, STDERR_FILENO);
		return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief Create philosopher
 *
 * @param philo: philo address
 * @param philo_id: philosopher id
 * @param arg: argument to be passed to philosopher therad routine
 * @param philo_data: philo data (philo args & fork mutexes)
 * @return t_bool: TRUE on success, FALSE otherwise
 */
static t_bool	ft_create_philosopher(t_philosopher *philo, int philo_id,
	void *arg, t_philo_data	*philo_data)
{
	int	thread_success;

	if (philo == NULL)
		return (FALSE);
	philo->id = philo_id;
	philo->philo_data = philo_data;
	philo->last_eat_time = 0;
	philo->eat_count = 0;
	usleep(50);
	thread_success
		= ft_create_thread(&philo->philo_thread, &ft_philo_routine, arg);
	if (thread_success == FALSE)
		return (FALSE);
	if (pthread_detach(philo->philo_thread) != 0)
		return (FALSE);
	else
		return (TRUE);
}

/**
 * @brief Initialize philosophers (ID & thread data)
 *
 * @param philo_data: philo data (philo args & fork mutexes)
 * @return t_philosopher*: newly created array of philosophers, NULL on failure
 */
t_philosopher	*ft_init_philosophers(t_philo_data *philo_data)
{
	t_philosopher	*philosophers;
	size_t			philo_count;
	size_t			i;
	t_bool			philo_success;

	if (philo_data == NULL)
		return (NULL);
	philo_count = philo_data->philo_args->philo_count;
	if (philo_count == 0)
		return (NULL);
	philosophers = ft_allocate(philo_count, sizeof(t_philosopher));
	if (philosophers == NULL)
		return (NULL);
	i = 0;
	while (i < philo_data->philo_args->philo_count)
	{
		philo_success
			= ft_create_philosopher
			(&philosophers[i], i + 1, &philosophers[i], philo_data);
		if (philo_success == FALSE)
			return (free(philosophers), NULL);
		++i;
	}
	return (philosophers);
}
