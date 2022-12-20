#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
    int frames; //total frames available
    printf("Enter the number of frames available\n");
    scanf("%d",&frames);
    int memory[frames];
    memset(memory,-1,sizeof(memory));
    
    
    int sl; // stream length
    printf("Enter the stream length\n");
    scanf("%d",&sl);
    int stream[sl];
    
    printf("Enter the stream programs\n");
    for(int i=0;i<sl;i++){
        scanf("%d",&stream[i]);       
    }
    
    int p=0; // pointing to the page in memory array
    int hit=0; // each time we find page in memory already
    
    for(int i=0;i<sl;i++){
        int flag=0;
        for(int j=0;j<frames;j++){
            if(memory[j]==stream[i]){
                hit++;flag=1; // found the page in memory
                break;
            }
        }
        if(!flag){
            if(p<frames)memory[p++]=stream[i]; // memory not filled completely yet
            else{                           // if memory filled we need to do replacement
                int copy[frames];           // copying memory array to copy array
                for(int j=0;j<frames;j++){
                    copy[j]=memory[j];
                }
                
                int cnt=0,ind=-1;
                for(int j=i-1;j>=0;j--){            // loop for backward tracing
                    for(int k=0;k<frames;k++){      //loop for copy array
                        if(copy[k]>=0 && copy[k]==stream[j]){ // checking one by one which programs are in memory
                            if(cnt==frames-1){
                                ind=k;          
                            }else{
                                copy[k]=-1;
                            }
                            cnt++;
                            break;
                        }
                    }
                    if(ind>=0)break;
                }
                memory[ind]=stream[i];// program which arrived most early will be replaced by current program
            }
        }
        for(int j=0;j<frames;j++){
            printf("%d ",memory[j]);
        }
        printf("\n");
    }
    printf("\nHit ratio - %d",(hit*100)/sl); // calculating total hit ratio
}
