/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:34:11 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/11 12:36:12 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_philo_routine(void *arg)
{
	printf("philo thread\n");
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
