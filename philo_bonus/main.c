#include "philo_bonus.h"

static int init_info(t_info *info, int argc, char **argv)
{
    info->num_philosophers = atoi(argv[1]);
    info->time_to_die = atoi(argv[2]);
    info->time_to_eat = atoi(argv[3]);
    info->time_to_sleep = atoi(argv[4]);
    info->num_times_each_philosopher_must_eat = (argc == 6) ? atoi(argv[5]) : -1;
    sem_unlink("/forks");
    sem_unlink("/message");
    sem_unlink("/death");
    sem_unlink("/all_eaten");
    sem_unlink("/lock");
    info->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, info->num_philosophers);
    info->message = sem_open("/message", O_CREAT | O_EXCL, 0644, 1);
    info->death = sem_open("/death", O_CREAT | O_EXCL, 0644, 0);
    info->lock = sem_open("/lock", O_CREAT | O_EXCL, 0644, 1);
    if (info->forks == SEM_FAILED || info->message == SEM_FAILED || info->death == SEM_FAILED)
        return (1);
    info->start_time = current_time();
    return (0);
}

static t_philosopher *init_philosophers(t_info *info)
{
    t_philosopher *philosophers;
    int i;

    philosophers = malloc(sizeof(t_philosopher) * info->num_philosophers);
    if (!philosophers)
        return (NULL);
    i = 0;
    while (i < info->num_philosophers)
    {
        philosophers[i].id = i + 1;
        philosophers[i].times_eaten = 0;
        philosophers[i].last_meal = info->start_time;
        philosophers[i].info = info;
        i++;
    }
    return (philosophers);
}

static void start_simulation(t_info *info, t_philosopher *philosophers)
{
    int i;

    i = 0;
    while (i < info->num_philosophers)
    {
        philosophers[i].pid = fork();
        if (philosophers[i].pid == 0)
            philosopher(&philosophers[i]);
        i++;
    }
    if (waitpid(-1, NULL, 0) || sem_wait(info->death))
        terminate_simulation(philosophers, info);
}
int main(int argc, char **argv)
{
    t_info info;
    t_philosopher *philosophers;

    if (argc != 5 && argc != 6)
    {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return (1);
    }
    if (init_info(&info, argc, argv))
        return (1);
    philosophers = init_philosophers(&info);
    if (!philosophers)
        return (1);
    start_simulation(&info, philosophers);
    free(philosophers);
    cleanup(&info);
    return (0);
}