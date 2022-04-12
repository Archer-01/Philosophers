/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:34:11 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/12 10:42:05 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_philo_routine(void *arg)
{
	t_philosopher	*philo;

	if (arg == NULL)
	{
		return (NULL);
	}
	philo = (t_philosopher *) arg;
	while (TRUE)
	{
		if (ft_get_fork(philo) == FALSE)
			return (NULL);
		if (ft_get_fork(philo) == FALSE)
			return (NULL);
		if (ft_eat(philo) == FALSE)
			return (NULL);
		if (ft_release_fork(philo) == FALSE)
			return (NULL);
		if (ft_release_fork(philo) == FALSE)
			return (NULL);
		if (ft_sleep(philo) == FALSE)
			return (NULL);
		if (ft_think(philo) == FALSE)
			return (NULL);
	}
	return (arg);
}

t_bool	ft_philo_thread(t_philosopher *philo)
{
	pthread_t	thread;

	if (philo == NULL)
		return (FALSE);
	if (ft_pthread_create(&thread, &ft_philo_routine, philo) == FALSE)
		return (FALSE);
	if (ft_pthread_join(thread) == FALSE)
		return (FALSE);
	return (TRUE);
}
