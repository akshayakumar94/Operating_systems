#include<stdio.h>
#include<unistd.h>

int main()
{
int pid=fork();
if (pid==0)
{
printf("Child process\n");
printf("%d\n",getpid());
}
else
{
printf("Parent process\n");
printf("%d\n",getpid());
}
return 0;
}
