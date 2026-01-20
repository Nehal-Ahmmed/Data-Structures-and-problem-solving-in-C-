#include<bits/stdc++.h>
using namespace std;

//normal recursion for array sum
int arraySum(int arr[], int i){
    if(i == 0){
        return arr[0];
    }
    return arr[i]+arraySum(arr, i-1);
}

//using tail call recursion for array sum
int arraySumTail(int arr[], int i, int result){
    if(i == 0){
        return arr[0]+result;
    }
    result = result + arr[i];
    return arraySumTail(arr, i-1, result);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Sum of array elements is: "<<arraySum(arr, n-1)<<endl;

    cout<<"Sum of array elements using tail call recursion is: "<<arraySumTail(arr, n-1, 0)<<endl;


    return 0;
}