#include<bits/stdc++.h>
using namespace std;

int b=7;
int a=2;
int res=0;

int mod(int n){
    if(n==0){
        return 1;
    }
    mod(n/2);
    int x=pow(a, n);
    res=x%b;
    return res;
}

int main(){
    mod(9);
    cout<<"Modulus: "<<res<<endl;
}