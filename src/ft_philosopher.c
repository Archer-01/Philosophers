/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:34:47 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/10 11:12:53 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_philosopher(unsigned int id, t_philo_data *philo_data)
{
	if (philo_data == NULL)
	{
		exit(EXIT_FAILURE);
	}
	sleep(id);
	printf("I'm philosopher no.%u\n", id);
	ft_destroy_philo_data(philo_data);
	exit(EXIT_SUCCESS);
}
