/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutexes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:48:44 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/23 03:48:45 by hhamza           ###   ########.fr       */
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

/**
 * @brief Destroy mutex
 *
 * @param mutex: pointer on mutex to destroy
 * @return t_bool: TRUE on success, FALSE otherwise
 */
static t_bool	ft_destroy_mutex(pthread_mutex_t *mutex)
{
	int	destroy_ret;

	if (mutex == NULL)
		return (FALSE);
	destroy_ret = pthread_mutex_destroy(mutex);
	if (destroy_ret != 0)
	{
		ft_putendl_fd(E_MUTEX_DESTROY, STDERR_FILENO);
		return (FALSE);
	}
	else
		return (TRUE);
}

/**
 * @brief Destroy mutexes
 *
 * @param mutexes: pointer on mutexes array
 * @param count: mutexes count
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_destroy_mutexes(pthread_mutex_t *mutexes, size_t count)
{
	size_t	i;

	if (mutexes == NULL)
		return (FALSE);
	i = 0;
	while (i < count)
	{
		if (ft_destroy_mutex(&mutexes[i]) == FALSE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
