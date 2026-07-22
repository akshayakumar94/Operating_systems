#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{

int pipefd[2];

pid_t pid;
char msg1[]="Hello child how are u?";
char msg2[]="I'm fine dad,how about u?";
char buffer[50];
pipe(pipefd);
pid=fork();

if (pid>0) // this is a parent process
{
close(pipefd[0]); // closing read end (0)

write(pipefd[1],msg1,sizeof(msg1));

write(pipefd[1],msg2,sizeof(msg2));
close(pipefd[1]);// closing write end (1)
}

else // child process
{
close(pipefd[1]);          // Close Write End
read(pipefd[0], buffer, sizeof(msg1));
printf("Child Received : %s\n", buffer);
read(pipefd[0], buffer, sizeof(msg2));
printf("Child Received : %s\n", buffer);
close(pipefd[0]);          // Close Read End
}
}    
