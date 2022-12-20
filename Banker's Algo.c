#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
    int n,res;
    printf("Enter the number of programs\n");
    scanf("%d",&n);
    printf("Enter the number of resources\n");
    scanf("%d",&res);
    
    int allocated[n][res]; //total instances of each resource allocated to each program
    int rem[res]; // total number of instances of each resources we can use
    
    memset(rem,0,sizeof(rem));
    
    printf("Enter available entities of resources\n");
    for(int i=0;i<res;i++)scanf("%d",&rem[i]);
    
    printf("Enter the allocated resources for programs\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<res;j++){
            scanf("%d",&allocated[i][j]);
            rem[j]-=allocated[i][j]; // calculating total instances of each resources remaining after each program get it's allocated resource share
        }
    }
    
    int needed[n][res]; // maximum instances required of each resource for a program to complete
    printf("Enter the needed resources for programs\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<res;j++){
            scanf("%d",&needed[i][j]);
            needed[i][j]-=allocated[i][j];
        }
    }
    
    int done[n]; // to check if a program is executed or not
    memset(done,0,sizeof(done));

    while(1){
        int flag=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            if(done[i])continue; // continue if a program is already executed
            flag=1;
            for(int j=0;j<res;j++){
                if(rem[j]>=needed[i][j]){
                    cnt++;
                }
            }
            if(cnt==res){
                printf("program-%d-->",i+1);
                for(int j=0;j<res;j++){
                    rem[j]+=needed[i][j];
                    needed[i][j]=0;
                }
                done[i]=1;
            }
        }
        if(!flag)break;
    }
}
