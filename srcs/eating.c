#include "../includes/philosophers.h"


int sleeping(t_philosopher *philo)
{
    message(philo, "is sleeping");
    usleep(*philo->time_to_sleep * 1000);
    return (EXIT_SUCCESS);
}

int eating(void *philo_ptr)
{
    t_philosopher *philo;
    struct timeval tv;
    
    philo = (t_philosopher *)philo_ptr;
    if (philo->dead == true)
        return (EXIT_SUCCESS);
    pthread_mutex_lock(philo->left_fork);
    message(philo, "has taken a fork");
    philo->nb_forks++;
    if (philo->dead == true)
    {
        pthread_mutex_unlock(philo->left_fork);
        return (EXIT_SUCCESS);
    }
    pthread_mutex_lock(philo->right_fork);
    philo->nb_forks++;
    message(philo, "has taken a fork");
    philo->is_not_eating = false;
    message(philo, "is eating");
    usleep(*philo->time_to_eat * 1000);
    gettimeofday(&tv,NULL);
    philo->time_of_last_meal = tv.tv_sec * 1000000 + tv.tv_usec;
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    philo->nb_forks = 0;
    philo->is_not_eating = true;
    return (EXIT_SUCCESS);
}