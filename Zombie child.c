#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int id=fork();
    if(id>0){
        sleep(10);
    }else{
        exit(0);
    }
}
