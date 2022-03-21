/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:54:44 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/21 04:03:00 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define E_USAGE_MSG "Usage: ./philo philo_num death_time eat_time sleep_time \
[min_eat_count]"
# define E_MALLOC_MSG "Error. malloc failed"
# define E_INVAL_MSG "Error. Invalid arguments"
# define E_PHILOCOUNT_MSG "Error. philosophers count must not exceed 200"
# define E_TIME_MSG "Error. time to die/sleep/eat must be 60ms or above"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_philo_args
{
	size_t			philo_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	min_eat_count;
}	t_philo_args;

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
t_bool			ft_isdigit(int c);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			*ft_allocate(size_t count, size_t size);
t_philo_args	*ft_parse_philo_args(int argc, char **argv);

#endif