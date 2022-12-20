#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

// Shared sender
int main()
{
    void *shared_memory;
    int shmid;
    char buffer[100];
    shmid=shmget((key_t)111,1024,0666|IPC_CREAT);
    printf("key of shared memory - %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("process attached at %p\n",shared_memory);
    printf("Enter the data in shared_memory\n");
    read(0,buffer,100);
    strcpy(shared_memory,buffer);
    printf("Enter data - %s\n",(char *)shared_memory);
}

// Shared Reciever
int main(){
    void *shared_memory;
    int shmid;
    char buffer[100];
    shmid=shmget((key_t)111,1024,0666);
    printf("key of shared memory %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Data read from share memory - %s\n",(char *)shared_memory);
}
