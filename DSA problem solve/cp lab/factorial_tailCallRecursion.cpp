#include<bits/stdc++.h>
using namespace std;

int fact(int n, int res){
    if(n==0){
        return 1;
    }

    return fact(n-1, n*res);
}

int main(){
    int res=1;
    cout<<"Factorial: "<<endl;
    cout<<fact(5, res);
    return 0;
}