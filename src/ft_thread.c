/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:50:43 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/05 10:32:59 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Create thread
 *
 * @param thread: thread object
 * @param routine: thread routine (function)
 * @param arg: argument to pass to routine
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_pthread_create(pthread_t *thread, t_routine routine, void *arg)
{
	int	ret;

	if (thread == NULL || routine == NULL)
	{
		return (FALSE);
	}
	ret = pthread_create(thread, NULL, routine, arg);
	if (ret != 0)
	{
		ft_putendl_fd(E_THREAD_CREATE_MSG, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}

/**
 * @brief Detach thread
 *
 * @param thread: thread object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_pthread_detach(pthread_t thread)
{
	int	ret;

	ret = pthread_detach(thread);
	if (ret != 0)
	{
		ft_putendl_fd(E_THREAD_DETACH_MSG, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}

/**
 * @brief Join thread
 *
 * @param thread: thread object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_pthread_join(pthread_t thread)
{
	int	ret;

	ret = pthread_join(thread, NULL);
	if (ret != 0)
	{
		ft_putendl_fd(E_THREAD_JOIN_MSG, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}
