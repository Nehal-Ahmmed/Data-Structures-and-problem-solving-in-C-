#include<bits/stdc++.h>
using namespace std;

int total=0;

int sum(int arr[],int n){
    if(n==0){
        return total;
    }
    total=total+arr[n-1];
    return sum(arr,n-1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

sum(arr,n);
cout<<"Sum of array elements: "<<total; 
}