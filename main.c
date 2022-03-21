/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:34:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/21 09:27:05 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_data	*philo_data;
	t_philosopher	*philosophers;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd(E_USAGE_MSG, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	philo_data = ft_init_philo_data(argc, argv);
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
