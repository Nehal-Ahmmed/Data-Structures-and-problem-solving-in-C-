#include<bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(){
    // Find all prime numbers up to n using Sieve of Eratosthenes : time complexity O(n log log n)
    int n= 100;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false; 

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }

    //display all prime numbers
    cout<<"Prime numbers up to "<<n<<": ";
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
}

int main(){
    sieveOfEratosthenes();
    return 0;
}