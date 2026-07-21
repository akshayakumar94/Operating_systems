#include<stdio.h> //header file to include printf and scanf
#include<sys/mman.h> //headerfile to include shared memory
#include<fcntl.h> //header file to include file related function O_Create, O_RDWR etc
#include<unistd.h> //unix standard library 
#include<string.h> //header file for string relatedc operations lik strcmp ,strcpy etc

int main()
{
int fd; // declare a file descriptor 

fd=shm_open("my_shm",O_CREAT| O_RDWR,0666);
//SYNTAX: shm_open(name of file, O_CREATE(creates a file | O_RDWR(open nd read/write the file),0666(default value)).

ftruncate(fd,1024);//ftruncates or maps the fd to size 1024

char *ptr=mmap(NULL,1024,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
strcpy(ptr,"Hello from Producer\n"); 
//this wont printed instead is written on the terminal
printf("Data written successfully\n");
munmap(ptr,1024);
close(fd);
return 0;
}

