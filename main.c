/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:34:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/05 11:39:14 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_args	*philo_args;
	t_philo_data	*philo_data;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd(E_USAGE_MSG, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	philo_args = ft_parse_philo_args(argc, argv);
	if (philo_args == NULL)
		return (EXIT_FAILURE);
	philo_data = ft_init_philo_data(philo_args);
	if (philo_data == NULL)
	{
		free(philo_args);
		return (EXIT_FAILURE);
	}
	printf("philosophers (bonus) is loading...\n");
	ft_destroy_philo_data(philo_data);
	return (0);
}
