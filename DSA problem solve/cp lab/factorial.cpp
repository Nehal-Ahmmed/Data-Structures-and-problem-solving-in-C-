#include<bits/stdc++.h>
using namespace std;

//factorial using recursion
int factorial(int n){
    if(n==0){
        return 1;
    }
    int fact = n * factorial(n-1);
    return fact;
}

int main(){
    cout<<"Factorial: "<<endl;
cout<<factorial(3);
    return 0;
}