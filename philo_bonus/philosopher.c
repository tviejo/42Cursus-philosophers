#include "philo_bonus.h"

void take_forks(t_philosopher *philo)
{
    sem_wait(philo->info->forks);
    print_message(philo, "has taken a fork");
    sem_wait(philo->info->forks);
    print_message(philo, "has taken a fork");
}

void put_forks(t_philosopher *philo)
{
    sem_post(philo->info->forks);
    sem_post(philo->info->forks);
}

void eat(t_philosopher *philo)
{
    take_forks(philo);
    philo->last_meal = current_time();
    philo->times_eaten++;
    print_message(philo, "is eating");
    msleep(philo->info->time_to_eat);
    put_forks(philo);
}

void sleep_and_think(t_philosopher *philo)
{
    print_message(philo, "is sleeping");
    msleep(philo->info->time_to_sleep);
}


void *check_death(void *philosopher)
{
    t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
    while (1)
    {
        if ((current_time() - philo->last_meal) > philo->info->time_to_die)
        {
            sem_post(philo->info->death);
            print_message(philo, "died");
            exit(1);
        }
    }
    return (NULL);
}

void philosopher(t_philosopher *philo)
{
    pthread_t death_checker;

    
    pthread_create(&death_checker, NULL, check_death, philo);
    while (1)
    {
        print_message(philo, "is thinking");
        eat(philo);
        if (philo->info->num_times_each_philosopher_must_eat != -1 &&
            philo->times_eaten >= philo->info->num_times_each_philosopher_must_eat)
            exit(0);
        sleep_and_think(philo);
        
    }
}