/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:54:44 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/05 09:39:46 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

# define E_USAGE_MSG "Usage: ./philo philo_num death_time eat_time sleep_time \
[min_eat_count]"
# define E_MALLOC_MSG "Error. malloc failed"
# define E_INVAL_MSG "Error. Invalid arguments"
# define E_PHILOCOUNT_MSG "Error. philosophers count must not exceed 200"
# define E_TIME_MSG "Error. time to die/sleep/eat must be 60ms or above"
# define E_SEM_OPEN_MSG "Error. failed to open/create semaphore"
# define E_SEM_CLOSE_MSG "Error. failed to close semaphore"
# define E_SEM_POST_MSG "Error. failed to post semaphore"
# define E_SEM_WAIT_MSG "Error. failed to wait semaphore"
# define E_SEM_UNLINK_MSG "Error. failed to unlink semaphore"

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

sem_t			*ft_sem_open(const char *name, unsigned int value);
t_bool			ft_sem_close(sem_t *sem);
t_bool			ft_sem_unlink(const char *name);
t_bool			ft_sem_post(sem_t *sem);
t_bool			ft_sem_wait(sem_t *sem);

#endif