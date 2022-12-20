#include<stdio.h>
#include<unistd.h>
int main(){
    
    char *path1="/bin/ls";
    char *path2="/bin/date";
    
    int pid=fork();
    
    if(pid>0){
        execl(path1,path1,NULL); // it will show all the files in path1
    } else{
        execl(path2,path2,NULL); // it will show the time
    }
}
