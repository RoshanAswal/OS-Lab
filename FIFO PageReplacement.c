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
            memory[p%frames]=stream[i]; // replacing the page if there was no hit
            p++;
        }
        for(int j=0;j<frames;j++){
            printf("%d ",memory[j]);
        }
        printf("\n");
    }
    printf("\nHit ratio - %d",(hit*100)/sl); // calculating total hit ratio
}
