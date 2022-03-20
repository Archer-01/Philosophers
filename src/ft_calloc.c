/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:13:16 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/20 06:28:15 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Allocate cout * size bytes in heap and sets everything to zero
 *
 * @param count: cout of elements to be allocated
 * @param size: size of each element in count
 * @return void*: allocated memory address
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	memset(ptr, 0, count * size);
	return (ptr);
}
