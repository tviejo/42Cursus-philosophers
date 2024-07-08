#include "../includes/philosophers.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_of_times_eat = ft_atoi(argv[5]);
	else
		data->nbr_of_times_eat = -1;
    return(EXIT_SUCCESS);
}
int init_philosophers(t_data *data)
{
    int i;

    i = 0;
    data->philo = malloc(sizeof(t_philosopher) * data->number_of_philo);
    if (data->philo == NULL)
        return (EXIT_FAILURE);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
    if (data->forks == NULL)
    {
        free(data->philo);
        return (EXIT_FAILURE);
    }
    while (i < data->number_of_philo)
    {
        data->philo[i].id = i + 1;
        data->philo[i].time_of_last_meal = data->start_time;
        data->philo[i].nbr_of_meals = 0;
        data->philo[i].dead = false;
        data->philo[i].time_to_die = &data->time_to_die;
        data->philo[i].time_to_eat = &data->time_to_eat;
        data->philo[i].time_to_sleep = &data->time_to_sleep;
        printf("Philosopher %d has been initialized\n", i);
        i++;
    }
    return(EXIT_SUCCESS);
}

int init_fork(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philo - 1)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        printf("Fork %d has been initialized\n", i);
        i++;
    }
    i = 0;
    while (i < data->number_of_philo)
    {
        data->philo[i].left_fork = &data->forks[i - 1];
        data->philo[i].right_fork = &data->forks[i];
        i++;
    }
    data->philo[0].left_fork = &data->forks[data->number_of_philo - 1];
    return(EXIT_SUCCESS);
}

int ft_init(t_data *data, int argc, char **argv)
{
    if (init_data(data, argc, argv))
    {
        printf("Error: init_data failed\n");
        return (EXIT_FAILURE);
    }
    if (init_philosophers(data))
    {
        printf("Error: init_philosophers failed\n");
        return (EXIT_FAILURE);
    }
    if (init_fork(data))
    {
        printf("Error: fork failed\n");
        return (EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);
}