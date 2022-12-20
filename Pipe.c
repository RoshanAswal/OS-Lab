#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int fd[2]; // fd[0] - for read , fd[1] - for write
    if(pipe(fd)==-1){
        printf("There was error in opening file\n");
        return 0;
    }
    int id=fork();
    if(id==0){ //child
        close(fd[0]); //closing the read side of pipe
        int x;
        printf("Enter the number\n");
        scanf("%d",&x);
        write(fd[1],&x,sizeof(int));  // writing in variable x
        close(fd[1]); //closing the write side of pipe
    }else{
        close(fd[1]); //closing the write side of pipe
        int y;
        read(fd[0],&y,sizeof(int));
        printf("value passed by child - %d\n",y);  // reading in variable x
        close(fd[0]); //closing the read side of pipe
    }
}
