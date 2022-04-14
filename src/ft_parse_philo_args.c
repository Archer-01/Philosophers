/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_philo_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 06:48:32 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/14 18:37:01 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Set philo aguments (Philosopers count, Time to die (ms), Time to eat
 * (ms), Time to sleep (ms) and Number of times each philosopher must eat
 * (optionnal)
 *
 * @param argc: argument count
 * @param argv: argument vector (array)
 * @param philo_args: pointer on philo arguments data structure
 */
static void	ft_set_philo_args(int argc, char **argv, t_philo_args *philo_args)
{
	if (argv == NULL || philo_args == NULL)
		return ;
	philo_args->philo_count = (size_t) ft_atoi(argv[1]);
	philo_args->time_to_die = (unsigned int) ft_atoi(argv[2]);
	philo_args->time_to_eat = (unsigned int) ft_atoi(argv[3]);
	philo_args->time_to_sleep = (unsigned int) ft_atoi(argv[4]);
	philo_args->min_eat_count = 0;
	if (argc == 6)
		philo_args->min_eat_count = (unsigned int) ft_atoi(argv[5]);
}

/**
 * @brief Check if string is a valid number.
 * Valid numbers may start with a single plus sign followed by digit characters
 * only afterwards.
 *
 * @param str: string to check
 * @return t_bool: TRUE on valid number string, FALSE otherwise
 */
static t_bool	ft_check_str_num(const char *str)
{
	int	i;

	if (str == NULL || str[0] == '\0')
		return (FALSE);
	i = 0;
	if (str[i] == '+')
		++i;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/**
 * @brief Check if philo arguments are valid number strings.
 *
 * @param argv: argument vector (array)
 * @return t_bool: TRUE on valid philo arguments, FALSE otherwise
 */
static t_bool	ft_check_philo_str_num(char **argv)
{
	int	i;

	if (argv == NULL)
		return (FALSE);
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_check_str_num(argv[i]) == FALSE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/**
 * @brief Check philo arguments validity.
 * Test if all arguments are valid number strings
 * Test if philosopher count is above 200, if so return FALSE
 * Test if time_to_die, time_to_eat and time_to_sleep are below 60ms if so
 * return FALSE
 * Also print appropriate error message if a condition is unfulfilled
 * If none of the above conditions apply, return TRUE
 *
 * @param argv: argument vector (array)
 * @param philo_args: pointer on philo args data structure
 * @return t_bool: TRUE on valid arguments, FALSE otherwise
 */
static t_bool	ft_check_philo_args(char **argv, t_philo_args *philo_args)
{
	if (philo_args == NULL)
		return (FALSE);
	if (ft_check_philo_str_num(argv) == FALSE)
	{
		ft_putendl_fd(E_INVAL_MSG, STDERR_FILENO);
		return (FALSE);
	}
	if (philo_args->philo_count > 200)
	{
		ft_putendl_fd(E_PHILOCOUNT_MSG, STDERR_FILENO);
		return (FALSE);
	}
	if (philo_args->time_to_die < 60 || philo_args->time_to_eat < 60
		|| philo_args->time_to_sleep < 60)
	{
		ft_putendl_fd(E_TIME_MSG, STDERR_FILENO);
		return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief Parse philo arguments
 *
 * @param argc: argument count
 * @param argv: argument vector (array)
 * @return t_philo_args*: pointer on malloc'd philo arguments. NULL on failure
 */
t_philo_args	*ft_parse_philo_args(int argc, char **argv)
{
	t_philo_args	*philo_args;

	philo_args = ft_allocate(1, sizeof(t_philo_args));
	if (philo_args == NULL)
		return (NULL);
	ft_set_philo_args(argc, argv, philo_args);
	if (argc == 6 && philo_args->min_eat_count == 0)
	{
		free(philo_args);
		return (NULL);
	}
	if (ft_check_philo_args(argv, philo_args) == FALSE)
	{
		free(philo_args);
		return (NULL);
	}
	return (philo_args);
}
