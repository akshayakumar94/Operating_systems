#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int pid=fork();
if (pid==0)
{
printf("Child process is created\n");
printf("Child process exiting with process id :%d\n",getpid());
}
else
{
printf("Parent process is created\n");
sleep(20);
printf("Parent process exiting with process id :%d\n",getpid());
/*in zombie process parent doesnt wait for the child ,which means despite child being finished since parent didnt call wait() it didnt get the status of the child hence it entry remains in process table... this is called as zombie process*/
}
return 0;
}

