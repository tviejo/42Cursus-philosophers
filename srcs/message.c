#include "../includes/philosophers.h"

bool ft_strncmp(char *msg, char *cmp, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (msg[i] != cmp[i])
            return (false);
        i++;
    }
    return (true);
}

int	message(t_philosopher *philo, char *msg)
{
    struct timeval tv;
	pthread_mutex_lock(philo->message);
    if (philo->dead == true && ft_strncmp(msg, "died", 4) == false)
    {
        pthread_mutex_unlock(philo->message);
        return (EXIT_FAILURE);
    }
    gettimeofday(&tv, NULL);
	printf("%ld Philosopher %d %s\n", (tv.tv_sec * 1000 + tv.tv_usec / 1000 - *philo->start_time), philo->id, msg);
	pthread_mutex_unlock(philo->message);
	return (EXIT_SUCCESS);
}