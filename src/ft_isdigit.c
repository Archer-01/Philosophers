/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:57:08 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/20 06:13:57 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Checks if character is a digit
 *
 * @param c: character to check
 * @return t_bool: TRUE for digit, false for non
 */
t_bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
