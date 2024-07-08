#include "../includes/philosophers.h"

int philosophers(t_data *data)
{
    int i;
    int j;

    j = 0;
    while (j < 10)
    {
    i = 0;
    while (i < data->number_of_philo)
    {
        pthread_create(&data->philo[i].thread, NULL, &eating, &data->philo[i]);
        i++;
    }
    while (i > 0)
    {
        pthread_join(data->philo[i].thread, NULL);
        i--;
    }
    j++;
    }
    return (EXIT_SUCCESS);
}