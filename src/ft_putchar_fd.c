/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:52:45 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/20 06:09:46 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Put a character to file pointed by file descriptor
 *
 * @param c: character to put
 * @param fd: file descriptor
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
