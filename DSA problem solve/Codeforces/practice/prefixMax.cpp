//prefix max array
// You are given an array of n
//  integers a1,a2,…,an

// The value of an array is the sum of the maximums of each prefix of the array. More formally, the value of an array a
//  is ∑ni=1max(a1,…,ai)
// . For example, the value of the array [1,2,1] is max(1)+max(1,2)+max(1,2,1)=1+2+2=5

// You can choose two indices i
//  and j
//  and swap elements ai
//  and aj
// ; this operation can be applied at most one time.

// Find the maximum possible value of the array a
//  after at most one operation.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,arraySize;
    cin>>t;
    while(t--){
        cin>>arraySize;
        int sum=0;
        int maxval=-1;
        int indexOfMax=-1;
        int arr[arraySize];
        for(int i=0; i<arraySize; i++){
            cin>>arr[i];
            if(arr[i]>maxval){
                maxval=arr[i];
                indexOfMax=i;
            }
        }

        int temp = arr[indexOfMax];
        arr[indexOfMax]=arr[0];
        arr[0]=temp;

        for(int i=0; i<arraySize; i++){
            if(i==0){
                sum+=arr[i];
                maxval=arr[i];
            }
            else{
                maxval= max(maxval, arr[i]);
                sum+=maxval;
            }
        }
        cout<<sum<<endl;
    }
}