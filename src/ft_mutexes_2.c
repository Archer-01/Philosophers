/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutexes_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 05:36:27 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/23 05:40:12 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Lock mutex
 *
 * @param mutex: mutex address
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_lock_mutex(pthread_mutex_t *mutex)
{
	int	lock_ret;

	if (mutex == NULL)
		return (FALSE);
	lock_ret = pthread_mutex_lock(mutex);
	if (lock_ret != 0)
	{
		ft_putendl_fd(E_MUTEX_LOCK, STDERR_FILENO);
		return (FALSE);
	}
	else
		return (TRUE);
}

/**
 * @brief Unlock mutex
 *
 * @param mutex: mutex address
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_unlock_mutex(pthread_mutex_t *mutex)
{
	int	unlock_ret;

	if (mutex == NULL)
		return (FALSE);
	unlock_ret = pthread_mutex_unlock(mutex);
	if (unlock_ret != 0)
	{
		ft_putendl_fd(E_MUTEX_UNLOCK, STDERR_FILENO);
		return (FALSE);
	}
	else
		return (TRUE);
}
