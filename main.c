/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:34:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/20 08:20:32 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_args	*philo_args;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd("Usage: ./philo philo_num death_time eat_time sleep_time \
[min_eat_count]", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	philo_args = ft_parse_philo_args(argc, argv);
	if (philo_args == NULL)
		return (EXIT_FAILURE);
	printf("philosophers is loading...\n");
	free(philo_args);
	return (0);
}
