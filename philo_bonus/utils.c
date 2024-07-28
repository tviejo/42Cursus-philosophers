#include "philo_bonus.h"

long int    current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void print_message(t_philosopher *philo, char *message)
{
    sem_wait(philo->info->message);
        printf("%lld %d %s\n", current_time() - philo->info->start_time, philo->id, message);
    sem_post(philo->info->message);
}

void msleep(int ms)
{
    usleep(ms * 1000);
}

void cleanup(t_info *info)
{
    sem_close(info->forks);
    sem_close(info->message);
    sem_close(info->death);
    sem_unlink("/forks");
    sem_unlink("/message");
    sem_unlink("/death");
}

void terminate_simulation(t_philosopher *philosophers, t_info *info)
{
    int i;

    for (i = 0; i < info->num_philosophers; i++)
    {
        kill(philosophers[i].pid, SIGKILL);
    }
}