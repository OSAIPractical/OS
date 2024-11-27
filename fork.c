#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
    int pid;
getpid;
pid=fork();
 if(pid==0)
 {
printf("\n Hi.., I am the child process ");
printf("\n My pid is %d ",getpid());
 }
else
 {
printf("\n pid of parent process is %d \n ",getpid());
 }
}