#include<stdio.h>
int Bsearch(int arr[],int l,int h,int x){
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==x)
        return mid;
        if(arr[mid]>x)
        h=mid-1;
        else
        l=mid+1;
    }
        return -1;
}
int main(){
    int n=9;
    int arr[]={1,2,3,4,5,6,7,8,9};
    int x=5;
    int result=Bsearch(arr,0,n-1,x);
    if(result==-1)
    printf("not found ");
    else
    printf("value at index : %d",result);
    return 0;
}