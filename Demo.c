/*
Write a program which creates two processess.
Process 1 count number of capital characters from demo.txt file. And process 2 count
number of capital characters from hello.txt file. Both the processess writes its count in
count.txt file.
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc , char * argv[])
{
    int ret1 = 0; int ret2 = 0; 
    int pid = 0 ; int status = 0;

    if( ret1 = fork() == 0)
    {
        printf("Child 1 process hasss started running \n");
        execl("./filexe" , argv[1] , argv[2] , NULL);
    }
    else
    {
        //How process 2 or child 2 can read the count of capital characters form file 2
        if( ret2 = fork() == 0)
        {
            printf("Child 2 process has started running \n");
            //execl("./filexe" , argv[2] ,NULL);
        }

        while( pid = wait(&status) > 0)
        {
            printf("Terminating childs pid is : %d \n" ,pid);
        }
    }
    printf("parent process has terminated \n");
    return 0;
}