/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 04:37:43 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/21 09:19:29 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Initialize philo data (philo_args & fork_mutextes)
 *
 * @param argc: argument count
 * @param argv: argument vector (array)
 * @return t_philo_data*: newly created philo data, NULL on failure
 */
t_philo_data	*ft_init_philo_data(int argc, char **argv)
{
	t_philo_data	*philo_data;

	if (argv == NULL)
		return (NULL);
	philo_data = ft_allocate(1, sizeof(t_philo_data));
	if (philo_data == NULL)
		return (NULL);
	philo_data->philo_args = ft_parse_philo_args(argc, argv);
	if (philo_data->philo_args == NULL)
	{
		ft_destroy_philo_data(philo_data);
		return (NULL);
	}
	philo_data->fork_mutexes
		= ft_init_mutexes(philo_data->philo_args->philo_count);
	if (philo_data->fork_mutexes == NULL)
	{
		ft_destroy_philo_data(philo_data);
		return (NULL);
	}
	return (philo_data);
}

/**
 * @brief Destroy philo data
 *
 * @param philo_data: philo data to operate on
 */
void	ft_destroy_philo_data(t_philo_data *philo_data)
{
	if (philo_data == NULL)
		return ;
	free(philo_data->philo_args);
	free(philo_data->fork_mutexes);
	free(philo_data);
}
