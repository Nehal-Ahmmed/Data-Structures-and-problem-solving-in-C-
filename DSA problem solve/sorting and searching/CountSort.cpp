#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr){
    if (arr.empty()) return;
    int max_value = *max_element(arr.begin(), arr.end());

    vector<int> count(max_value+1, 0);

    for(int num : arr){
        count[num]++;
    }

    //cumulative count
    for(int i=1; i<=max_value ; i++){
        count[i]= count[i]+count[i-1];
    }

    //output array
    vector<int> ouput(arr.size());

    for(int i=arr.size()-1; i>=0; i--){
        ouput[count[arr[i]] -1] = arr[i];
        count[arr[i]]--;
    }

    arr = ouput;
}

int main(){
    vector<int> arr= {4,2,2,8,3,3,1};
    countSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
    
}