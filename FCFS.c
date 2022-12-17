/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void swap(int arr[],int a,int b){
    int t=arr[a];
    arr[a]=arr[b];
    arr[b]=t;
}
int main()
{
    int n;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    int arrival[n],burst[n],completion[n],tat[n],wait[n],response[n];
    printf("Enter the values of arrival time and burst time\n");
    for(int i=0;i<n;i++){
        scanf("%d%d",&arrival[i],&burst[i]);
    }
    // sorting both arrival and burst arrays
    for(int i=0;i<n;i++){
        int min=arrival[i];
        int ind=-1;
        for(int j=i;j<n;j++){
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
    int t=0,i=0;
    while(i<n){
        if(t<arrival[i])t=arrival[i];
        t+=burst[i];
        
        completion[i]=t;
        tat[i]=completion[i]-arrival[i];
        wait[i]=tat[i]-burst[i];
        
        if(i==0 || (i>0 && completion[i-1]<=arrival[i]))
            response[i]=0;
        else
            response[i]=completion[i-1]-arrival[i];
        
        printf("%d %d %d %d %d %d\n",arrival[i],burst[i],completion[i],tat[i],wait[i],response[i]);
        i++;
    }
}
