#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

// Shared sender
int main()
{
    void *shared_memory; // for shared memory location 
    int shmid; 
    char buffer[100]; // for data storage
    shmid=shmget((key_t)111,1024,0666|IPC_CREAT); // creating shared_memory (key,amount of data,giving read and write permission)
    printf("key of shared memory - %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0); // location of shared memory
    printf("process attached at %p\n",shared_memory);
    printf("Enter the data in shared_memory\n");
    read(0,buffer,100); // reading from keyboard into buffer atmax 100 bytes
    strcpy(shared_memory,buffer); // copying data from buffer to shared_memory
    printf("Enter data - %s\n",(char *)shared_memory);
}

// Shared Reciever
int main(){
    void *shared_memory;
    int shmid;
    char buffer[100];
    shmid=shmget((key_t)111,1024,0666); // getting same id as shared Reciever
    printf("key of shared memory %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0); // getting memory location of shared_memory
    printf("Process attached at %p\n",shared_memory);
    printf("Data read from share memory - %s\n",(char *)shared_memory); // printing shared_memory data
}
