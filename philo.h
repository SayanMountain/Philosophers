#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <sys/semaphore.h>
#include "sys/time.h"

#define KNRM  "\x1B[0m"      //// белый
#define KRED  "\x1B[31m"     //// красный
#define KGRN  "\x1B[32m"     //// зеленый
#define KYEL  "\x1B[33m"     //// желтый
#define KBLU  "\x1B[34m"     //// синий
#define KMAG  "\x1B[35m"     //// фиолетовый
#define KCYN  "\x1B[36m"     //// бирюзовый
#define KWHT  "\x1B[37m"     //// серый

//printf("\x1B[32mПроцесс № %p\n",&t.mutex[i]);
//printf("\x1B[34mThread %d has started\t\n", j);

//typedef struct          s_table            //// СТОЛ
//{
//    struct s_philo      *param;
//    int                 philo_size;
//    int                 time_to_die;
//    int                 time_to_eat;
//    int                 time_to_sleep;
//    int                 how_many_eat;
//    int                 fork_to_malloc;
//    pthread_t           *ph;               //// потоки
//}                       t_table;

//typedef struct          s_philo            //// ФИЛОСОФЫ
//{
//    pthread_mutex_t     *fork_left;
//    pthread_mutex_t     *fork_right;
//    struct s_table      *param2;
//    struct t_philo1     *tPhilo1;
//}                       t_philo;
//
//typedef struct          s_each_philo
//{
//    int                 fork_right;
//    int                 fork_left;
//    int                 filo1;
//
//}                       t_philo1;


typedef struct          s_tred
{
    pthread_t           philo;
    int                 act;
    int                 numb_philo;
    pthread_mutex_t     *left;      //// левая рука философа
    pthread_mutex_t     *right;     //// правая рука философа
}                       t_tred;

typedef struct          s_philo
{
    pthread_mutex_t     *mutex;
    int                 i;
    t_tred              *tred;
    int                 philo_num;
    int                 common_time;
    int                 philo_eat;
    int                 philo_sleep;
    int                 time_to_eat;
}                       t_philo;

//struct timeval {
//    time_t          tv_sec;    ////sec
//    suseconds_t     tv_usec;   ////microsec
//};

//t_philo *g_s;

int         ft_atoi(char *str);
void        eat();
void        night();
long        function_for_check_time();
void        go_bad(int lenght);

#endif