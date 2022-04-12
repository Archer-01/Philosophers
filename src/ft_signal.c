/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:51:59 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/12 18:28:27 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Send signal to a process
 *
 * @param pid: Process ID
 * @param sig: signal number
 * @return int: 0 on success, -1 on failure
 */
int	ft_kill(pid_t pid, int sig)
{
	int	ret;

	ret = kill(pid, sig);
	if (ret == -1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}
