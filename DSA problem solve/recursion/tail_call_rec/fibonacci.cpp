#include<bits/stdc++.h>
using namespace std;

int tailFib(int n, int a=0, int b=1){
    if(n==0) return a;
    if(n==1) return b;
    return tailFib(n-1, b, a+b);
}

int main(){
    for(int i=0; i<=10; i++){
        cout<<"Fibonacci of "<<i<<" is: "<<tailFib(i)<<endl;
    }
}