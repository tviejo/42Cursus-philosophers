# include "../includes/philosophers.h"

int ft_close(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philo)
    {
        // pthread_mutex_destroy(data->philosophers[i].left_fork);
        printf("Philosopher %d has been destroyed\n", i);
        i++;
    }
    return (0);
}