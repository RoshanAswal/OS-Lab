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
    
    int quant;
    printf("Enter the quant value\n");
    scanf("%d",&quant);
    
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
    
    int readyQ[n+1],inqueue[n]; // initializing ready Queue and inqueue array
    readyQ[0]=0;inqueue[0]=1;  // 1st program will be in readyQ 

    for(int i=0;i<n;i++)response[i]=-1; // response time initializing with -1

    for(int i=1;i<n;i++)inqueue[i]=0; // all other programs are not in queue

    int t=arrival[0],lastind=1,allin=0; // t = timer , lastind = to check the last item in ready queue ,  allin = to check if all are in queue
    
    while(1){
        if(lastind==0){ // if lastind==0 then there is no program left
            break;
        }
        int program=readyQ[0]; // getting first program from readyQ
        
        for(int i=0;i<lastind-1;i++){ // shifting all programs in queue 3>2>1
            readyQ[i]=readyQ[i+1];
        }
        
        lastind=lastind-1; // decreasing the lastind because first program is preemptive
        int again=0; 
        
        if(response[program]<0)response[program]=t-arrival[program];
        
        if(tempburst[program]<=quant){
            t=t+tempburst[program];
            tempburst[program]=0;
            completion[program]=t;
            tat[program]=completion[program]-arrival[program];
            wait[program]=tat[program]-burst[program];
        }else{
            t=t+quant;
            tempburst[program]=tempburst[program]-quant;
            again=1;
        }

        if(allin<n){ // checking if all programs in queue or not, if not then insert in readyQ
            for(int i=0;i<n;i++){
                if(arrival[i]<=t && inqueue[i]==0 && tempburst[i]>0){
                    inqueue[i]=1;
                    readyQ[lastind]=i;
                    lastind=lastind+1;
                }
            }            
        }

        if(again){ // if first program not completed then it is inserted back in readyQ
            readyQ[lastind]=program;
            lastind=lastind+1;
        }
        allin=0;
        for(int i=0;i<n;i++){
            if(inqueue[i]==1)allin=allin+1;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",arrival[i],burst[i],completion[i],tat[i],wait[i],response[i]);
    }
    return 0;
}
