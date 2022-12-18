#include <stdio.h>

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int main()
{
    int n;
    printf("Enter the number of programs\n");
    scanf("%d",&n);
    int arrival[n],burst[n],completion[n],tat[n],wait[n],response[n],tempburst[n];
    printf("Enter the arrival time and burst time of each program\n");
    int mxburst=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&arrival[i],&burst[i]);
        tempburst[i]=burst[i];
        if(mxburst<burst[i])mxburst=burst[i];
        response[i]=-1;
    }
    
    // Sorting 
    for(int i=0;i<n;i++){
        int ind=-1,min=arrival[i];
        for(int j=i+1;j<n;j++){
            if(min>arrival[j]){
                min=arrival[j];
                ind=j;
            }
        }
        if(ind>i){
            swap(arrival,i,ind);
            swap(burst,i,ind);
        }
    }
    
    int t=arrival[0];
    
    while(1){
        int ind=-1,mn=mxburst+1,completed=0;
        
        for(int i=0;i<n;i++){  // checking program with smallest burst time remaining and arrival time less than t (current time) 
            if(arrival[i]<=t && tempburst[i]<mn && tempburst[i]>0){
                mn=tempburst[i];
                ind=i;
            }
            if(tempburst[i]==0)completed++; // counting all the process which already completed
        }
        
        if(completed==n)break; // if all the process completed then we break
        
        if(ind>=0){
            if(response[ind]==-1)response[ind]=t-arrival[ind]; // first time when program get cpu
            tempburst[ind]=tempburst[ind]-1; // decreasing burst time of program
            if(tempburst[ind]==0){
                completion[ind]=t+1; // calculating completion time of program
                tat[ind]=completion[ind]-arrival[ind]; // turn around time of program i.e total time between arrival of program in queue to completion
                wait[ind]=tat[ind]-burst[ind]; // waiting time of program after getting first time cpu
            }
        }
        t++; // increasing timer
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d %d %d %d %d %d\n",arrival[i],burst[i],completion[i],tat[i],wait[i],response[i]);
    }
    return 0;
}
