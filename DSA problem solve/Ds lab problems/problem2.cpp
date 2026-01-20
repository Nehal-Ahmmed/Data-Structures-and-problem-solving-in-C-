#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4,2,2,8,3,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target ;
    cout<<"enter your target integer: ";
    cin>>target;

    sort(arr, arr+n);
    for(int n: arr){
        cout<<n<<" ";
    }

    int i=0;
    while (arr[i]<target)
    {
        i++;
    }
    i= i-1;
    cout<<"\n init index is: "<<i;
    int j =0, k,flag=0;

    while (i!=j)
    {
        k=  arr[i]+arr[j];
        if(k==target){
            cout<<"\nPain found at index : "<<i<<" and "<<j;
            flag=1;
            break;
        }
        else if(k<target){
            j++;
        }
        else{
            i--;
        }
    }
    
if(flag==0){
    cout<<"\nPair not found";
}
}