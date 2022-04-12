/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:52:34 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/12 18:11:14 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Get time of day (Get current timestamp)
 *
 * @param timestamp: timestamp address to write in
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_gettimeofday(time_t *timestamp)
{
	struct timeval	timeval;
	int				ret;

	if (timestamp == NULL)
	{
		return (FALSE);
	}
	ret = gettimeofday(&timeval, NULL);
	if (ret == -1)
	{
		ft_putendl_fd(E_GETTIME_MSG, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		*timestamp = (timeval.tv_sec * 1000) + (time_t)(timeval.tv_usec / 1000);
		return (TRUE);
	}
}

/**
 * @brief Suspend thread execution for an interval measured in microseconds
 *
 * @param time: time interval in microseconds
 * @return t_bool: TRUE on success, FALSE on failure
 */
t_bool	ft_usleep(useconds_t time)
{
	int	ret;

	ret = usleep(time);
	if (ret == -1)
	{
		ft_putendl_fd(E_USLEEP_MSG, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}
