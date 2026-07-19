//This is the program which creates 2 threads 
#include<stdio.h>
#include<pthread.h>
void *display1(void *args)
{
int *n=(int *)args;
*n=*n+10;
printf("This is the function inside thread :1 with value %d\n",*n);
return NULL;
}
void *display2(void *args)
{
char *c=(char*)args;
printf("This is the function inside thread :2 with value %c\n",*c);
return NULL;
}


int main()
{
int a=10;
char b='a';
pthread_t t1,t2;
pthread_create(&t1,NULL,display1,&a);

pthread_create(&t2,NULL,display2,&b); 
/*This function creates a thread 
&tid -refers to the thread id
NULL -refers to thread attributes (currently NULL)
display - refers to the code /function that the thread executes ,
NULL- refers to the value passed to function*/

pthread_join(t1,NULL);
pthread_join(t2,NULL);
/* Function to join a newly created thread with id (tid )with main thread
Also blocks or pauses the main thread to wait for the new thread to finish its execution*/

printf("Back to the main thread \n");

return 0;
}

