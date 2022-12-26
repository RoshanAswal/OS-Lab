#include <stdio.h>
#include <unistd.h>
int main()
{
    int arr[]={1,2,3,4,5};
    int id=fork();
    int sumEven=0,sumOdd=0;
    if(id==0) // a child process
    {
        for(int i=0;i<5;i++){
            if(arr[i]&1)sumOdd+=arr[i];
        }
        printf("Parent process\n");
        printf("Odd sum - %d\n",sumOdd);
    }else if(id>0){
        for(int i=0;i<5;i++){
            if(!(arr[i]&1))sumEven+=arr[i];
        }
        printf("Child process\n");
        printf("Odd sum - %d\n",sumEven);
    }
    return 0;
}
