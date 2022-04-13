/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:18:07 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/13 13:17:18 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Open a named semaphore.
 * Also create semaphore if it doesn't exist
 *
 * @param name: semaphore name
 * @param value: semaphore initial value
 * @return sem_t*: semaphore object, SEM_FAILED on failure
 */
sem_t	*ft_sem_open(const char *name, unsigned int value)
{
	sem_t	*sem;

	if (name == NULL)
	{
		return (SEM_FAILED);
	}
	sem = sem_open(name, O_CREAT, 0600, value);
	if (sem == SEM_FAILED)
	{
		ft_putendl_fd(E_SEM_OPEN_MSG, STDERR_FILENO);
		return (SEM_FAILED);
	}
	else
	{
		return (sem);
	}
}

/**
 * @brief Close a names semaphore
 *
 * @param sem: semaphore object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_sem_close(sem_t *sem)
{
	int	ret;

	if (sem == NULL)
	{
		return (FALSE);
	}
	ret = sem_close(sem);
	if (ret == -1)
	{
		ft_putendl_fd(E_SEM_CLOSE_MSG, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}

/**
 * @brief Unlink (Remove) a named semaphore
 *
 * @param name: semaphore name
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_sem_unlink(const char *name)
{
	int	ret;

	if (name == NULL)
	{
		return (FALSE);
	}
	ret = sem_unlink(name);
	if (ret == -1)
	{
		ft_putendl_fd(E_SEM_UNLINK_MSG, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}

/**
 * @brief Post (Unlock) a semaphore
 *
 * @param sem: semaphore object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_sem_post(sem_t *sem)
{
	int	ret;

	if (sem == NULL)
	{
		return (FALSE);
	}
	ret = sem_post(sem);
	if (ret == -1)
	{
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}

/**
 * @brief Wait (Lock) semaphore
 *
 * @param sem: semaphore object
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_sem_wait(sem_t *sem)
{
	int	ret;

	if (sem == NULL)
	{
		return (FALSE);
	}
	ret = sem_wait(sem);
	if (ret == -1)
	{
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}
