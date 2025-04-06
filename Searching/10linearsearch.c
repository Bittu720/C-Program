#include<stdio.h>
int main(){
int arr[]={1,3,2,4,5,7,6};
int n=7,i;
int x=4;
for(i=0;i<n;i++){
    if(arr[i]==x){
        printf("value at index : %d",i);
        break;
}
}
if(i==n){
    printf("Not found ");
}
return 0;
}