#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
int pipefd[2]; 
// 2 pipe descriptors 0 for reading 1 for writing
char write_msg[]= "hello this is a pipe ipc program";
char read_msg[20];

int status;

status =pipe(pipefd);
// to read status if pipe is created or not 

if(status==-1)
{
printf("Pipe creation failed\n");
}

write(pipefd[1],write_msg,sizeof(write_msg));
// write(pipe_descriptor, msg to write, size of msg to write)
// for writing pipe descriptor 1 is used 

read(pipefd[0],read_msg,sizeof(read_msg));

//for reading msg pipe decriptor 0 is used 

printf("Message read :%s \n",read_msg);
}

