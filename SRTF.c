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
        
        for(int i=0;i<n;i++){  // checking smallest remaining program
            if(arrival[i]<=t && tempburst[i]<mn && tempburst[i]>0){
                mn=tempburst[i];
                ind=i;
            }
            if(tempburst[i]==0)completed++;
        }
        
        if(completed==n)break;
        
        if(ind>=0){
            printf("%d ",ind+1);
            if(response[ind]==-1)response[ind]=t-arrival[ind];
            tempburst[ind]=tempburst[ind]-1;
            if(tempburst[ind]==0){
                completion[ind]=t+1;
                tat[ind]=completion[ind]-arrival[ind];
                wait[ind]=tat[ind]-burst[ind];
            }
        }
        t++;
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d %d %d %d %d %d\n",arrival[i],burst[i],completion[i],tat[i],wait[i],response[i]);
    }
    return 0;
}
