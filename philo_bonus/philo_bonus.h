#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

typedef struct s_philosopher
{
    int             id;
    int             times_eaten;
    long long       last_meal;
    struct s_info   *info;
    pid_t           pid;
}               t_philosopher;

typedef struct s_info
{
    int             num_philosophers;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             num_times_each_philosopher_must_eat;
    long long       start_time;
    sem_t           *forks;
    sem_t           *message;
    sem_t           *death;
    sem_t           *lock;
}               t_info;

// utils.c
long int    current_time(void);
void        print_message(t_philosopher *philo, char *message);
void custom_sleep_eating(long time_last_meal, long time_to_eat);
void custom_sleep_sleeping(long timestamp, long time_to_sleep);
void        cleanup(t_info *info);
void        terminate_simulation(t_philosopher *philosophers, t_info *info);

// philosopher.c
void        philosopher(t_philosopher *philo);

#endif