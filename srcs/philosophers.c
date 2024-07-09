#include "../includes/philosophers.h"

int dead_philo(t_data *data)
{
    int i;
    int j;
    struct timeval tv;
    long time;

    i = 0;
    while (i < data->number_of_philo)
    {
        if (data->philo[i].is_not_eating == true)
        {
            gettimeofday(&tv,NULL);
            time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
            if (time - data->philo[i].time_of_last_meal > *data->philo[i].time_to_die)
            {
                message(&data->philo[i], "died");
                j = 0;
                while (j < data->number_of_philo)
                {
                    data->philo[j].dead = true;
                    j++;
                }
                data->one_is_dead = true;
                return (EXIT_FAILURE);
            }
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

void *living_philo(void *philosopher)
{
    t_philosopher *philo;
    int j;

    philo = (t_philosopher *)philosopher;
    while (philo->dead == false && *philo->end == false)
    {
        message(philo, "is thinking");
        if (philo->id % 2 == 1)
            eating_left(philo);
        else
            eating_right(philo);
        sleeping(philo);
    }
    return (NULL);
}
int philosophers(t_data *data)
{
    int i;
    int j;
    int all_meals;

    i = 0;
    while (i < data->number_of_philo)
    {
        if (data->philo[i].dead == false)
            pthread_create(&data->philo[i].thread, NULL, &living_philo, &data->philo[i]);
        i++;
    }
    data->end = false;
    while (data->one_is_dead == false && data->end == false)
    {
        if (everyone_ate(data) == true)
            data->end = true;
        dead_philo(data);
    }
    
    i = 0;
    while (i < data->number_of_philo)
    {
        pthread_join(data->philo[i].thread, NULL);
        i++;
    }
    return (EXIT_SUCCESS);
}