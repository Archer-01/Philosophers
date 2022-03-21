/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 05:30:29 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/21 09:34:01 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Create mutex
 *
 * @param mutex: mutex address
 * @return t_bool: TRUE on success, FALSE otherwise
 */
static t_bool	ft_create_mutex(pthread_mutex_t *mutex)
{
	int	mutex_success;

	if (mutex == NULL)
		return (FALSE);
	mutex_success = pthread_mutex_init(mutex, NULL);
	if (mutex_success != 0)
	{
		ft_putendl_fd(E_MUTEX_CREAT, STDERR_FILENO);
		return (FALSE);
	}
	else
		return (TRUE);
}

/**
 * @brief Initialize fork mutexes
 *
 * @param count: mutexes count
 * @return pthread_mutex_t*: mutex array, NULL otherwise
 */
pthread_mutex_t	*ft_init_mutexes(size_t count)
{
	pthread_mutex_t	*mutexes;
	size_t			i;
	int				mutex_success;

	mutexes = ft_allocate(count, sizeof(pthread_mutex_t));
	if (mutexes == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		mutex_success = ft_create_mutex(&mutexes[i]);
		if (mutex_success == FALSE)
		{
			free(mutexes);
			return (NULL);
		}
		++i;
	}
	return (mutexes);
}
