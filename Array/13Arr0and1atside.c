#include<stdio.h>
int main(){
    int n;
    printf("enter size of array :");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements :");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int temp=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
             arr[temp++]=arr[i];
        }
    }
        while(temp<n){
    arr[temp++]=0;
}
printf("after move element :");
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

    return 0;
}