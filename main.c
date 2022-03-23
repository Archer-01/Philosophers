/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:34:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/23 04:46:11 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_data	*philo_data;
	t_philosopher	*philosophers;
	time_t			*begin_timestamp;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd(E_USAGE_MSG, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	begin_timestamp = ft_get_timestamp_ptr();
	if (begin_timestamp == NULL)
		return (EXIT_FAILURE);
	philo_data = ft_init_philo_data(argc, argv, begin_timestamp);
	if (philo_data == NULL)
		return (EXIT_FAILURE);
	philosophers = ft_init_philosophers(philo_data);
	if (philosophers == NULL)
	{
		ft_destroy_philo_data(philo_data);
		return (EXIT_FAILURE);
	}
	sleep(1);
	ft_destroy_philo_data(philo_data);
	free(philosophers);
	return (0);
}
