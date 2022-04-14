/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:53:49 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/14 22:25:00 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Single philosopher child process function
 * (Helper function for ft_single_philosopher)
 *
 * @param philo_args: philosopher arguments object
 * @return t_bool: exit process on success, return FALSE on failure
 */
static t_bool	ft_single_child(t_philo_args *philo_args)
{
	if (philo_args == NULL)
	{
		return (FALSE);
	}
	printf("0 1 has taken a fork\n");
	if (ft_usleep(philo_args->time_to_die * 1000) == FALSE)
	{
		free(philo_args);
		exit(EXIT_FAILURE);
	}
	free(philo_args);
	exit(EXIT_SUCCESS);
}

/**
 * @brief Single philosopher case (Handled separatly due to sem_close hanging)
 * @note This function always exits
 *
 * @param philo_args: philosopher arguments object
 */
void	ft_single_philosopher(t_philo_args *philo_args)
{
	pid_t	pid;

	pid = ft_fork();
	if (pid == -1)
	{
		free(philo_args);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		ft_single_child(philo_args);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (ft_waitpid(pid) == FALSE)
		{
			free(philo_args);
			exit(EXIT_FAILURE);
		}
		printf("%u 1 died\n", philo_args->time_to_die);
		free(philo_args);
		exit(EXIT_SUCCESS);
	}
}
