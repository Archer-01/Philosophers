/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:54:44 by hhamza            #+#    #+#             */
/*   Updated: 2022/04/12 18:28:56 by hhamza           ###   ########.fr       */
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
# define E_THREAD_CREATE_MSG "Error. failed to create thread"
# define E_THREAD_DETACH_MSG "Error. failed to detach thread"
# define E_THREAD_JOIN_MSG "Error. failed to join thread"
# define E_GETTIME_MSG "Error. gettimeofday failed"
# define E_FORK_MSG "Error. fork failed to create a process"
# define E_WAITPID_MSG "Error. failed to wait for a process"
# define E_KILL_MSG "Error. failed to kill a process"
# define E_PROCESS_EXIT_MSG "Error. child process exited with failure"
# define E_USLEEP_MSG "Error. usleep failed"

# define FORK_SEM_NAME "/fork_sem"
# define WRITE_SEM_NAME "/writing_sem"

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

typedef void	*(*t_routine)(void *);

typedef struct s_philo_data
{
	t_philo_args	*philo_args;
	sem_t			*fork_sem;
	sem_t			*writing_sem;
	time_t			begin_time;
}	t_philo_data;

typedef struct s_philosopher
{
	unsigned int	id;
	t_philo_data	*philo_data;
	time_t			last_eat_time;
	unsigned int	eat_count;
	t_bool			is_dead;
}	t_philosopher;

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

t_bool			ft_pthread_create(pthread_t *thread, t_routine routine, \
	void *arg);
t_bool			ft_pthread_detach(pthread_t thread);
t_bool			ft_pthread_join(pthread_t thread);

t_bool			ft_gettimeofday(time_t *timestamp);
t_bool			ft_usleep(useconds_t time);

t_philo_data	*ft_init_philo_data(int argc, char **argv);
void			ft_destroy_philo_data(t_philo_data *philo_data);

pid_t			ft_fork(void);
t_bool			ft_waitpid(pid_t pid);

int				ft_kill(pid_t pid, int sig);

pid_t			*ft_create_philosophers(t_philo_data *philo_data);
t_bool			ft_wait_philosophers(pid_t *pids, size_t count);
t_bool			ft_kill_philosophers(pid_t *pids, size_t count);

void			ft_philo_process(unsigned int id, t_philo_data *philo_data);

t_bool			ft_philo_thread(t_philosopher *philo);

t_bool			ft_think(t_philosopher *philo);
t_bool			ft_get_fork(t_philosopher *philo);
t_bool			ft_eat(t_philosopher *philo);
t_bool			ft_release_fork(t_philosopher *philo);
t_bool			ft_sleep(t_philosopher *philo);

#endif