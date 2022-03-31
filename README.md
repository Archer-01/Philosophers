# Philosophers

Philosophers is an implementation of the ***Dining Philosophers*** synchronization problem via multi-threading (Using the pthread API)

## Philosophers (threads activity)
<img src="./doc/philo-activity.png" alt="Philosophers (threads) activity" height="700">

## Main thread activity
![Philosopher reaper (main thread) activity](doc/philo-reaper-activity.png)

## Usage
```sh
make
./philo philo_num death_time eat_time sleep_time [min_eat_count]
```

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)