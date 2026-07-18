#include<stdio.h>
#include<unistd.h>
int main()
{
int pid=fork();

if (pid==0)
{
printf("Child process is runing with id:%d\n",getpid());
sleep(10);
printf("\nParent had already exited new parent id:%d\n",getppid());
}
else
{
printf("Parent process with id:%d is exiting....\n",getppid());
}
}
/*Here the parents exits before the child finishes it task making it a orphan, as a result the linux will automatically allocate a parent to the child with a new ppid(parent process id )different frm that of the original parent's process id*/

