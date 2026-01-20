#include<bits/stdc++.h>
using namespace std;

int findMax(int arr[], int n, int currnetMax){
    if(n==0){
        return currnetMax;
    }

    int newMax= max(currnetMax, arr[0]);
    return findMax(arr+1, n-1, newMax);
}


int main(){
    int arr[] = {3, 5, 2, 9, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxElement = findMax(arr, n, arr[0]);
    cout<<"Maximum element in the array is: "<<maxElement<<endl;

    return 0;
}