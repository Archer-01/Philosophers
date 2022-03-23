/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 05:14:38 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/23 03:13:51 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Get current timestamp
 *
 * @param timestamp_ptr: pointer to save timestamp in
 * @return t_bool: TRUE on success, FALSE otherwise
 */
t_bool	ft_get_timestamp(time_t *timestamp_ptr)
{
	struct timeval	timeval;
	int				ret;

	if (timestamp_ptr == NULL)
		return (FALSE);
	ret = gettimeofday(&timeval, NULL);
	if (ret == -1)
	{
		ft_putendl_fd(E_TIMESTAMP, STDERR_FILENO);
		return (FALSE);
	}
	*timestamp_ptr
		= (timeval.tv_sec * 1000) + (time_t)(timeval.tv_usec / 1000);
	return (TRUE);
}

/**
 * @brief Get pointer on current timestamp
 *
 * @return time_t*: newly created timestamp pointer, NULL on failure
 */
time_t	*ft_get_timestamp_ptr(void)
{
	time_t	*begin_timestamp;

	begin_timestamp = ft_allocate(1, sizeof(time_t));
	if (begin_timestamp == NULL)
		return (NULL);
	else if (ft_get_timestamp(begin_timestamp) == FALSE)
		return (NULL);
	else
		return (begin_timestamp);
}
