#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int id=fork();
    if(id==0){
        //child process
        sleep(10);
        printf("child finished\n");
    }else{
        printf("parent not waiting\n");
    }
}
