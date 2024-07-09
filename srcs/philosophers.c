#include "../includes/philosophers.h"

int dead_philo(t_philosopher *philo)
{
    struct timeval tv;
    long int time;
    int i;

    if (philo->is_not_eating == true)
        {
            gettimeofday(&tv,NULL);
            time = tv.tv_sec * 1000000 + tv.tv_usec;
            if (time - philo->time_of_last_meal > *philo->time_to_die * 1000)
            {
                message(philo, "died");
                philo->dead = true;
                return (EXIT_FAILURE);
            }
        }
    return (EXIT_SUCCESS);
}

void *living_philo(void *philosopher)
{
    t_philosopher *philo;
    int j;

    philo = (t_philosopher *)philosopher;
    while (philo->dead == false)
    {
        if (dead_philo(philo) == EXIT_FAILURE)
            return (NULL);
        message(philo, "is thinking");
        eating(philo);
        sleeping(philo);
    }
    return (NULL);
}
int philosophers(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->number_of_philo)
    {
        printf("Philosopher %d is alive\n", i);
        if (data->philo[i].dead == false)
            pthread_create(&data->philo[i].thread, NULL, &living_philo, &data->philo[i]);
        i++;
    }
    i = 0;
    while (i < data->number_of_philo)
    {
        if (data->philo[i].dead == false)
            pthread_join(data->philo[i].thread, NULL);
        i++;
    }
    return (EXIT_SUCCESS);
}