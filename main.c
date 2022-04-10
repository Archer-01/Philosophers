/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:34:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/10 11:16:01 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_data	*philo_data;
	pid_t			*pids;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd(E_USAGE_MSG, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	philo_data = ft_init_philo_data(argc, argv);
	if (philo_data == NULL)
		return (EXIT_FAILURE);
	pids = ft_create_philosophers(philo_data);
	if (pids == NULL)
		return (ft_destroy_philo_data(philo_data), EXIT_FAILURE);
	if (!ft_wait_philosophers(pids, philo_data->philo_args->philo_count))
	{
		ft_destroy_philo_data(philo_data);
		free(pids);
		return (EXIT_FAILURE);
	}
	ft_destroy_philo_data(philo_data);
	free(pids);
	return (0);
}
