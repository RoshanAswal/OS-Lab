#include<stdio.h>
#include<stdlib.h>
int main(){
    int tracks;
    printf("Enter the number tracks on disk\n");
    scanf("%d",&tracks);
    
    int disk[tracks];
    printf("Enter the tracks\n");
    for(int i=0;i<tracks;i++){
        scanf("%d",&disk[i]);
    }
    
    int head;
    printf("Enter the head of Read/Write head\n");
    scanf("%d",&head);
    
    int trackmov=0;
    for(int i=0;i<tracks;i++){
        trackmov+=abs(head-disk[i]);
        head=disk[i];
    }
    printf("Total tracks movement - %d\n",trackmov);
}
