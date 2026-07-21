#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

sem_t sem;// creating the semaphore

void *task(void *args)
{
sem_wait(&sem);
printf("Thread entered into critical section successfully\n");

sleep(3);
printf("Thread leaving critical section successfully\n");

sem_post(&sem);

return NULL;
}

int main()
{
pthread_t t1,t2,t3;
sem_init(&sem,0,1);
pthread_create(&t1,NULL,task,NULL);
pthread_create(&t2,NULL,task,NULL);
pthread_create(&t3,NULL,task,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
sem_destroy(&sem);
return 0;
}

