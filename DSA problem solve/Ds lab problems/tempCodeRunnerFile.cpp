#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,j=0,index,flag= 0;
    cout<<"Enter size of array: ";
    cin>>n;
    index= n-1;
    int arr[n];

    cout<<"Enter elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    while (j<n)
    {
        if(index==j){
            cout<<"Can reach to the end of array? = true"<<endl;
            flag=1;
            break;
        }
        j+=arr[j];
    }
    
    if(flag==0){
        cout<<"Can reach to the end of array? = false"<<endl;
    }

    cout<<"Array elements are: "<<endl;
    for(int n: arr){
        cout<<n<<" ";
    }
}