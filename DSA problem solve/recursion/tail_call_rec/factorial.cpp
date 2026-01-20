#include<bits/stdc++.h>
using namespace std;

//normal recursion for factorial
int fact(int n){
    if(n==0){
        return 1;
    }

    return n*fact(n-1);
}

//using tail call recursion for factorial
int tailFact(int n, int result){
    if(n==0){
        return result;
    }

    return tailFact(n-1, n*result);
}



int main(){
    int n=5;
    cout<<"Factorial of "<<n<<" is: "<<fact(n)<<endl;
    cout<<"Factorial of "<<n<<" using tail call recursion is: "<<tailFact(n, 1)<<endl;

    return 0;
}