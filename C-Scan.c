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
    mov+=((total-1)-arr[tracks-1]); // adding track movement from last given number to the total track in disk
    mov+=total-1; // adding total track number in track movement because header will move from total-1 to 0
    
    curr=0;
    for(int i=0;i<hi;i++){ // second printing all the smaller track numbers but starting from 0
        printf("Pno. %d - ",arr[i]);
        mov+=(arr[i]-curr);
        curr=arr[i];
    }
    printf("\nTotal track movement - %d",mov);
}
