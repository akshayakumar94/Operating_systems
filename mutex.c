#include<stdio.h>
#include<pthread.h>

int c=0;
pthread_mutex_t a; //creating the mutex variable a 

void *func(void *args)
{
for(int i=0;i<1000;i++)
{
pthread_mutex_lock(&a); //Locks the critical section and marks its entry 
c=c+1; // critical section - section of code where the shared resource can be accessed.
pthread_mutex_unlock(&a); //Unlocks the critical section and marks its exit 
}
}

int main()
{
pthread_mutex_init(&a,NULL); //initialising the mutex
pthread_t t1,t2; //creating 2 threads t1,t2.

pthread_create(&t1,NULL,func,NULL); 
pthread_create(&t2,NULL,func,NULL);

pthread_join(t1,NULL);
pthread_join(t2,NULL);

pthread_mutex_destroy(&a);//destroying the mutex a 

printf("Value of C is %d\n",c);
return 0;
}

