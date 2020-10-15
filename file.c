/*
    problems that i am facing : 

    //How to write the count from File 1 : hello.txt & File 2 : demo.txt in File 3 : Count.txt
    //How process 2 or child 2 can read the count of capital characters form file 2
    
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc , char * argv[])
{
    int fd = 0 , fd2 = 0;

    int ret = 0 , i = 0 , icnt = 0;    char buffer[1024];

    int ret2 = 0 , j = 0 , icnt2 = 0;  char buffer2[1024];

    int fd3 = 0 , ret3 = 0; char buffer3[1024];

    //open File 1 : hello.txt
    printf("\nThe file that the child 1 is trying to  opened is :  %s \n" , argv[0]);
    fd = open(argv[0] , O_RDWR);
    if( fd == -1)
    {
        printf("Error : Unable to open the File 1 : %s \n" , argv[0]);
        return -1;
    }
    printf("File 1 :| %s | !!! is opened \n" , argv[0]);

    memset(buffer , 0 , sizeof(buffer));
    //read the data from File 1 : hello.txt
    ret = read(fd , buffer , sizeof(buffer) );
    if( ret == -1)
    {
        printf("Error : Unable to read the data from the File 1 : %s \n" ,argv[0]);
        return -1;
    }

    printf("The data read from the File 1 : | %s | is  : | %s | \n" , argv[0] , buffer);
    printf("No of bytes read from the File 1 :| %s | are : %d \n" , argv[0] , ret);

    //count the nummber of capital characters in File 1 : hello.txt
    for(i = 0 ; i < ret ; i++)
    {
        if ( ( buffer[i] >= 'A') &&( buffer[i] <= 'Z') )
        {
            icnt++;
        }
    }
    printf("The count of capital characters present in the data in File 1 : hello.txt  is : %d \n", icnt);

    printf("\nThe file that the child 2 is trying to  opened is :  %s \n" , argv[1]);
    //open File 2 : demo.txt
    fd2 = open(argv[1] , O_RDWR);
    if( fd2 == -1)
    {
        printf("Error : unable to open File 2\n");
        return -1;
    }
    printf("\nFile 2 : | %s | !!! is opened : \n", argv[1]);
        memset(buffer2 , 0 , sizeof(buffer2));
    //read the data from File 2 : demo.txt
    ret2 = read(fd2 , buffer2 , sizeof(buffer2));
    if( ret2 == -1)
    {
        printf("Error : Unable to read the data from the File 2 : %s \n" ,argv[1]);
        return -1;
    }
    printf("The data read from File 2 is : %s \n" , buffer2);
    printf("The number of bytes read fomm File 2 : %d \n", ret2 );

    //count the nummber of capital characters in File 2 : demo.txt
    for( j = 0 ; j < ret2 ; j++)
    {
        if( ( buffer2[j] >= 'A' ) && (buffer2[j] <= 'Z'))
        {
            icnt2++;
        }
    }
    printf("The count of capital characters present in the data in File 2 are : %d \n" , icnt2);

    
    // fd3 = open(argv[3] , O_RDWR);
    // if( fd3 == -1)
    // {
    //     printf("Error : Unbale to open File 3 : %s\n",argv[3]);
    //     return -1;
    // }
    // printf("\nFile 3 : | %s | !!! is opened \n" , argv[3]);

    
    //ret3 = write(fd3 , buffer2 , sizeof(buffer2) );
    return 0;
}
