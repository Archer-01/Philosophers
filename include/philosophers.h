/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:54:44 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/28 04:35:04 by hhamza           ###   ########.fr       */
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
# define E_MUTEX_CREAT "Error. failed to create mutex"
# define E_MUTEX_DESTROY "Error. failed to destroy mutex"
# define E_THREAD_CREAT "Error. failed to create thread"
# define E_TIMESTAMP "Error. gettimeofday failed"
# define E_MUTEX_LOCK "Error. failed to lock mutex"
# define E_MUTEX_UNLOCK "Error. failed to unlock mutex"
# define E_INVAL_ACT "Error. Invalid philosopher activity"

# define ACT_THINK "Think"
# define ACT_FORK "Take a fork"
# define ACT_EAT "Eat"
# define ACT_SLEEP "Sleep"

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

typedef struct philo_data
{
	t_philo_args	*philo_args;
	pthread_mutex_t	*fork_mutexes;
	time_t			*begin_timestamp;
	pthread_mutex_t	writing_mutex;
}	t_philo_data;

typedef struct s_philosopher
{
	unsigned int	id;
	pthread_t		philo_thread;
	t_philo_data	*philo_data;
}	t_philosopher;

typedef void	*(*t_routine)(void *);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
t_bool			ft_isdigit(int c);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			*ft_allocate(size_t count, size_t size);
int				ft_strcmp(const char *s1, const char *s2);

t_philo_args	*ft_parse_philo_args(int argc, char **argv);
t_bool			ft_create_mutex(pthread_mutex_t *mutex);
pthread_mutex_t	*ft_init_mutexes(size_t count);
t_bool			ft_destroy_mutexes(pthread_mutex_t *mutexes, size_t count);
t_bool			ft_lock_mutex(pthread_mutex_t *mutex);
t_bool			ft_unlock_mutex(pthread_mutex_t *mutex);
t_philo_data	*ft_init_philo_data(int argc, char **argv, \
	time_t *begin_timestamp);
void			ft_destroy_philo_data(t_philo_data *philo_data);
t_philosopher	*ft_init_philosophers(t_philo_data *philo_data);
t_philosopher	*ft_philosophers(int argc, char **argv);
void			ft_destroy_philosophers(t_philosopher *philosophers);

t_bool			ft_think(t_philosopher *philo);
t_bool			ft_get_fork(t_philosopher *philo, unsigned int fork_id);
t_bool			ft_eat(t_philosopher *philo);
t_bool			ft_release_fork(t_philosopher *philo, unsigned int fork_id);
t_bool			ft_sleep(t_philosopher *philo);
void			*ft_philo_routine(void *arg);

t_bool			ft_thread_print(const char *activity, time_t timestamp, \
	unsigned int philo_id, pthread_mutex_t *writing_mutex);

t_bool			ft_get_timestamp(time_t *timestamp_ptr);
time_t			*ft_get_timestamp_ptr(void);

#endif