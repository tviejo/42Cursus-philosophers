#include "philo_bonus.h"

void	custom_sleep_eating(long time_last_meal, long time_to_eat)
{
    while (current_time() - time_last_meal < time_to_eat)
    {
        usleep(10);
    }
}

void	custom_sleep_sleeping(long timestamp, long time_to_sleep)
{
    while (current_time() - timestamp < time_to_sleep)
    {
        usleep(10);
    }
}