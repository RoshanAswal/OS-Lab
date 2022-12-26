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
    
    if(arr[0]>head)hi=-1;  // if head is less than lowest number provided then head index<0
    if(arr[tracks-1]<head)hi=tracks+1; // if head is higher than number provided than head>total tracks
    
    int mov=0; // total track movement initialized with 0
    int l=hi-1,r=hi,curr=head; // using two pointers approach
    
    while(l>=0 || r<tracks){
        if(l>=0 && r<tracks){ // if we have two options
            if(curr-arr[l]<arr[r]-curr){ // if left value if less than right value
                mov+=(curr-arr[l]);
                curr=arr[l];
                l--;
            }else{  
                mov+=(arr[r]-curr);
                curr=arr[r];
                r++;
            }
        }else if(l<0){ // if we have only one option left
            mov+=(arr[r]-curr);
            curr=arr[r];
            r++;
        }else{ // if we have only one option left
            mov+=(curr-arr[l]);
            curr=arr[l];
            l--;
        }
        printf("Pno. %d - ",curr);
    }
    printf("\nTotal track movement - %d",mov);
    
}
