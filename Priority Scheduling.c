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
    int arrival[n],burst[n],priority[n],completion[n],tat[n],wait[n],response[n],tempburst[n];
    printf("Enter the arrival time, burst time and priority of each program\n");
    
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arrival[i],&burst[i],&priority[i]);
        tempburst[i]=burst[i];
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
            swap(priority,i,ind);
        }
    }
    
    int t=0; // timer
    
    while(1){
        int mx=-1,program=-1;
        for(int i=0;i<n;i++){
            if(arrival[i]>t)break;
            if(tempburst[i]>0 && priority[i]>mx){ // finding the program which is in readyQ(below timer) and highest priority
                program=i;
            }
        }
        
        tempburst[program]-=1; // reducing burst time of program
        
        if(response[program]<0)response[program]=t; //response time

        if(tempburst[program]==0){
            completion[program]=t+1;
            tat[program]=completion[program]-arrival[program];
            wait[program]=tat[program]-burst[program];
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){ // checking if all programs are fininshed
            if(tempburst[i]==0)cnt++;
        }
        if(cnt==n)break;
        t++;
    }
    
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",arrival[i],burst[i],completion[i],tat[i],wait[i],response[i]);
    }
}
