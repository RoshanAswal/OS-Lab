#include <stdio.h>

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int main()
{
    int total,tracks;
    printf("Enter total tracks and number of trakc numbers\n");
    scanf("%d%d",&total,&tracks);
    printf("Enter the track numbers\n");
    int arr[tracks];
    for(int i=0;i<tracks;i++){
        scanf("%d",&arr[i]);
    }
    
    int head,hi=-2; // initializing head index as -2
    printf("Enter the read write head position\n");
    scanf("%d",&head);
    
    // sorting
    for(int i=0;i<tracks;i++){
        int mn=arr[i],ind=i;
        for(int j=i+1;j<tracks;j++){
            if(mn>arr[j]){
                mn=arr[j];ind=j;
            }
        }
        swap(arr,i,ind);
        if(arr[i]>=head && hi<-1)hi=i;
    }
    
    if(arr[0]>head)hi=0;  // if head is less than lowest number provided then head index=0
    if(arr[tracks-1]<head)hi=tracks-1; // if head is higher than number provided than head=total tracks
    
    int mov=0; // total track movement initialized with 0
    int curr=head;
    if(arr[hi]==head){ // if first program is head then we print it
        printf("Pno. %d - ",head);
        hi++;
    }
    for(int i=hi;i<tracks;i++){ //first printing all the larger track numbers
        printf("Pno. %d - ",arr[i]);
        mov+=(arr[i]-curr);
        curr=arr[i];
    }

    mov+=(arr[tracks-1]-arr[0]); // adding difference of last track number and first track number
    // this is only difference between c look and c scan 
    // in c look we don't need to move to the end of disk or to the starting of disk
    
    curr=arr[0];
    for(int i=0;i<hi;i++){ // second printing all the smaller track numbers but starting from 0
        printf("Pno. %d - ",arr[i]);
        mov+=(arr[i]-curr);
        curr=arr[i];
    }
    printf("\nTotal track movement - %d",mov);
}
