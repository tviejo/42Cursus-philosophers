#include "../includes/philosophers.h"


int sleeping(t_philosopher *philo)
{
    printf("Philosopher %d is sleeping\n", philo->id);
    usleep(*philo->time_to_sleep * 1000);
    return (EXIT_SUCCESS);
}

void *eating(void *philo_ptr)
{
    t_philosopher *philo;
    
    philo = (t_philosopher *)philo_ptr;
    printf("Philosopher %d is thinking\n", philo->id);
    pthread_mutex_lock(philo->left_fork);
    printf("Philosopher %d has taken a fork\n", philo->id);
    pthread_mutex_lock(philo->right_fork);
    printf("Philosopher %d has taken a fork\n", philo->id);
    printf("Philosopher %d is eating\n", philo->id);
    usleep(*philo->time_to_eat * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    sleeping(philo);
    return (NULL);
}