#include "philo.h"

void *life(void *structure)
{
    t_tred *t;
//    t_philo *t1;

    t = (t_tred *)structure;
    printf("!!num philo = %d!!\n", t->numb_philo);
//    int len;
//    int i;
//    t_philo s;

//    s = *g_s;
//    int i = 0;
//    usleep(500);
//    printf("\nTYT\n");
    while (1)
    {
        pthread_mutex_lock(t->left);
//        printf("mutex_right %p\n", t->left); ////// принтф вилка залочена ли
        pthread_mutex_lock(t->right);
//        printf("mutex_right %p\n", t->right); //////принтф вилка залочена ли

        ////// принтф такой то философ начал есть
        eat();
        pthread_mutex_unlock(t->left);
        pthread_mutex_unlock(t->right);
        night();
//        printf("\n\nTYT i TYT\n");
    }

}


void eat ()
{
    printf("\x1B[32m EAT\n");
}

void night()
{
    printf("\x1B[35m NIGHT\n");
}

int main(int argc, char **argv)
{
    t_philo t;
    int i = 0;
//    int j = 0;

    argc = 0;

    t.philo_num     = ft_atoi(argv[1]);
    t.common_time   = ft_atoi(argv[2]);
    t.philo_eat     = ft_atoi(argv[3]);
    t.philo_sleep   = ft_atoi(argv[4]);
    t.mutex = malloc(sizeof(pthread_mutex_t) * t.philo_num);
    t.tred = malloc(sizeof (t_tred) * t.philo_num);
    t.tred->act = 0;                                                //// для того, чтобы смотреть кто и где

//    g_s = &t;
    i = 0;
    while(i < t.philo_num)
    {
        pthread_mutex_init(&t.mutex[i], NULL);                          //// 1 создаю mutex
        t.tred->act++;
//        printf("\nMutex_init %d has activated\t", i);
//        printf("Процесс № %p\t",&t.mutex[i]);
//        printf("Операция № %d\t",t.tred->act - 1);
        i++;
    }

    i = 0;
    while(i < t.philo_num) //// модернизировал до работы циклов по четным нечетным потокам
    {
        t.tred[i].numb_philo = i + 1;
        t.tred[i].left = &t.mutex[i];
        if (i != t.philo_num - 1)
            t.tred[i].right = &t.mutex[i + 1];
        else
            t.tred[i].right = &t.mutex[0];
        pthread_create(&t.tred[i].philo, NULL, &life, (void *)&t.tred[i]);
        printf("\nTred Left  %p\n", t.tred[i].left);
        printf("Tred Right %p\n", t.tred[i].right);
        pthread_detach(t.tred[i].philo);
//        }
//        else
//        {
//            exit(0);    /////// пока буду работать с четным числом философов
//            //            t.tred[i].left = &t.mutex[i];
//            //            t.tred[i].right = &t.mutex[i + 1];
//            //            pthread_create(&t.tred[j].philo, NULL, &all, &i);
//            j++;
//        }
        i++;
//        printf("\n\nTYT\n");
    }
}







