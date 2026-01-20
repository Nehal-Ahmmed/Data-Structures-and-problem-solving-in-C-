#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 7;

//Problem Statement: Given x and n, compute (x^n)%7 where, 0 <= x, n <= 105, either x or n will be positive.
int BigMod(int x, int n){
    if(n==0){
        return 1;
    }else if(n%2){
        return (x%mod * BigMod(x, n-1)%mod) % mod;
    }else{
        ll half = BigMod(x, n/2)%mod;
        return (half * half) % mod;
    }
}

//inversed mod : a/b mod m
int inversedMod(int a, int b){
    return (a % mod * BigMod(b, mod-2) % mod) % mod;
}

int main(){
    int x, n;
    cout<<"Enter the value of x and n: ";
    cin>>x>>n;
    cout<<"("<<x<<"^"<<n<<") % "<<mod<<" = "<<BigMod(x, n)<<endl;

    int a, b;
    cout<<"Enter the value of a and b for a/b mod "<<mod<<": ";
    cin>>a>>b;
    cout<<"("<<a<<"/"<<b<<") % "<<mod<<" = "<<inversedMod(a, b)<<endl;

    return 0;
}