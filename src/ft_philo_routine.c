/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:57:48 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/22 04:21:53 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philo_routine(void *arg)
{
	t_philosopher	*philo;
	size_t			fork_count;
	size_t			first_fork;
	size_t			second_fork;

	if (arg == NULL)
		return (NULL);
	usleep(100);
	philo = (t_philosopher *) arg;
	fork_count = philo->philo_data->philo_args->philo_count;
	if (fork_count == 1)
	{
		printf("Yo, i'm philosopher no.%u - I can use one fork only\n",
			philo->id);
		return (NULL);
	}
	first_fork = philo->id - 1;
	second_fork = ((size_t) philo->id) % fork_count;
	printf("Yo, i'm philosopher no.%u - I can use the forks %zu and %zu\n",
		philo->id, first_fork, second_fork);
	return (NULL);
}
