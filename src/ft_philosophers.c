/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:19:14 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/28 04:40:37 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Create philosophers
 *
 * @param argc: argument count
 * @param argv: argument vector (array)
 * @return t_philosopher*: philosophers array, NULL on failure
 */
t_philosopher	*ft_philosophers(int argc, char **argv)
{
	time_t			*begin_timestamp;
	t_philo_data	*philo_data;
	t_philosopher	*philosophers;

	if (argv == NULL)
		return (NULL);
	begin_timestamp = ft_get_timestamp_ptr();
	if (begin_timestamp == NULL)
		return (NULL);
	philo_data = ft_init_philo_data(argc, argv, begin_timestamp);
	if (philo_data == NULL)
		return (NULL);
	philosophers = ft_init_philosophers(philo_data);
	if (philosophers == NULL)
	{
		ft_destroy_philo_data(philo_data);
		return (NULL);
	}
	return (philosophers);
}

/**
 * @brief Destroy all philosophers allocated memory
 *
 * @param philosophers: philosophers array
 */
void	ft_destroy_philosophers(t_philosopher *philosophers)
{
	if (philosophers == NULL)
		return ;
	ft_destroy_philo_data(philosophers->philo_data);
	free(philosophers);
}
