#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4,2,2,8,3,3,1,-1,-4,-3,-4,0,0};

    int pos=0, neg=0, zero=0;
    for(int n: arr){
        if(n>0){
            pos++;
        }
        else if(n<0){
            neg++;
        }
        else{
            zero++;
        }
    }

    int arr_pos[pos-2];
    int arr_neg[neg];
    int arr_zero[zero+2];

    for(int i=0 ; i<(zero+2) ; i++){
        arr_zero[i]=0;
    }

    int i=0, j=0, k=0;
    for(int n: arr){
        if(n>0){
            if(i>=(pos-2)){
                arr_zero[k]= n;
                k++;
            }else{
                arr_pos[i]= n;
                i++;
            }
            
        }
        else if(n<0){
            arr_neg[j]= n;
            j++;
        }
        else{
            arr_zero[k]= n;
            k++;
        }
    }

    int indexNonZero=0;
    for(int i=0 ; i<zero+2 ; i++){
        if(arr_zero[i]!=0){
            indexNonZero= i;
            break;
        }
    }

    if(neg%2==0){
        int temp = arr_neg[neg-1];
        arr_neg[neg-1]= arr_zero[indexNonZero];
        arr_zero[indexNonZero]= temp;
    }

    cout<<"Positive Array: "<<endl;
    for(int n: arr_pos){
        cout<<n<<" ";
    }
    cout<<endl;
    cout<<"Negative Array: "<<endl;
    for(int n: arr_neg){
        cout<<n<<" ";
    }
    cout<<endl;
    cout<<"Zero and Positive Array: "<<endl;
    for(int n: arr_zero){
        cout<<n<<" ";
    }
}