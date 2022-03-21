/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 04:01:43 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/21 04:04:48 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Allocate count * size bytes on heap.
 * Also print error message on failure.
 *
 * @param count: element count
 * @param size: individual element size
 * @return void*: allocated pointer address, NULL on failure
 */
void	*ft_allocate(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
	{
		ft_putendl_fd(E_MALLOC_MSG, STDERR_FILENO);
		return (NULL);
	}
	return (ptr);
}
