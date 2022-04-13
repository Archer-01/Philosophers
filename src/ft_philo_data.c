/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:18:03 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/13 12:15:18 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Unlink semaphores needed by this program
 */
static void	ft_unlink_semaphores(void)
{
	sem_unlink(FORK_SEM_NAME);
	sem_unlink(WRITE_SEM_NAME);
}

/**
 * @brief Initialize philo data
 *
 * @param argc: command line arguments count
 * @param argv: command line arguments vector (array)
 * @return t_philo_data*: philo data, NULL on failure
 */
t_philo_data	*ft_init_philo_data(int argc, char **argv)
{
	t_philo_data	*philo_data;
	t_philo_args	*philo_args;

	if (argv == NULL)
		return (NULL);
	ft_unlink_semaphores();
	philo_args = ft_parse_philo_args(argc, argv);
	if (philo_args == NULL)
		return (NULL);
	philo_data = ft_allocate(1, sizeof(t_philo_data));
	if (philo_data == NULL)
	{
		free(philo_args);
		return (NULL);
	}
	philo_data->philo_args = philo_args;
	philo_data->fork_sem = ft_sem_open(FORK_SEM_NAME, philo_args->philo_count);
	if (philo_data->fork_sem == SEM_FAILED)
		return (free(philo_args), NULL);
	philo_data->writing_sem = ft_sem_open(WRITE_SEM_NAME, 1);
	if (philo_data->fork_sem == SEM_FAILED)
		return (free(philo_args), NULL);
	if (ft_gettimeofday(&philo_data->begin_time) == FALSE)
		return (free(philo_args), NULL);
	return (philo_data);
}

/**
 * @brief Destroy philo data
 *
 * @param philo_data: philo data address
 */
void	ft_destroy_philo_data(t_philo_data *philo_data)
{
	if (philo_data == NULL)
		return ;
	ft_sem_close(philo_data->writing_sem);
	ft_sem_close(philo_data->fork_sem);
	free(philo_data->philo_args);
	free(philo_data);
}
