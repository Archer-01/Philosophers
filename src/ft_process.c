/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:35:09 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/10 10:18:27 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Create a process
 *
 * @return pid_t: Process ID, -1 on failure
 */
pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd(E_FORK_MSG, STDERR_FILENO);
		return ((pid_t)(-1));
	}
	else
	{
		return (pid);
	}
}

/**
 * @brief Wait for process to change state
 *
 * @param pid: Process ID
 * @return t_bool: TRUE if process terminated successfully, FALSE otherwise
 */
t_bool	ft_waitpid(pid_t pid)
{
	int	ret;
	int	status;

	ret = waitpid(pid, &status, 0);
	if (ret == -1)
	{
		ft_putendl_fd(E_WAITPID_MSG, STDERR_FILENO);
		return (FALSE);
	}
	else
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			ft_putendl_fd(E_PROCESS_EXIT_MSG, STDERR_FILENO);
			return (FALSE);
		}
		else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		{
			return (TRUE);
		}
		else
		{
			return (FALSE);
		}
	}
}
