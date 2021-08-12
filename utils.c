//#include "philo.h"

//#define NUM 1000000
//#define NUM2 10000000
//
//float time_diff(struct timeval *start, struct timeval *end)
//{
//    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
//}
//
//void loopFunc(size_t num)
//{
//    int tmp = 0;
//    for (int i = 0; i < num; ++i)
//    {
//        tmp += 1;
//    }
//}
//
////int gettimeofdat (struct timeval *tp, struct  timezone *tz)
//int main()
//{
//    struct timeval tv_sec;
//    struct timeval tv_usec;
//
//    gettimeofday(&tv_sec, NULL);
//    loopFunc(NUM);
//    gettimeofday(&tv_usec, NULL);
//    printf("loopFunc(%d)  time spent: %0.8f sec\n", NUM2, time_diff(&tv_sec, &tv_usec));
//
//    gettimeofday(&tv_sec, NULL);
//    loopFunc(NUM2);
//    gettimeofday(&tv_usec, NULL);
//    printf("loopFunc(%d)  time spent: %0.8f sec\n", NUM2, time_diff(&tv_sec, &tv_usec));
//
//    exit(EXIT_SUCCESS);
//
//
////    (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
////    printf("current time", )
//}


//
//long start_time = get_time();   //// текущее время
//
//

#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main ()
{
    time_t              end_of_eat;
    time_t              end_of_sleep;
    long unsigned int   t;



    end_of_eat = time(NULL);

    printf("\x1B[34m Время после eat: %s\n", ctime (&ttime));
    return 0;
}

void go_bad(int lenght)
{
   long time;

   time = function_for_check_time();
   while(function_time() < time + lenght)
       usleep(lengt);
}

long function_for_check_time ()
{
    struct timeval       time1;
    gettimeofday(&time1, NULL);
    return (time1.tv_sec * 1000 + time1.tv_usec / 1000);
}