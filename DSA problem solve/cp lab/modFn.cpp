#include<bits/stdc++.h>
using namespace std;

int mod(int a, int n, int m) {
    if (n == 0) {
        return 1 ;
    }
    
    long long temp = mod(a, n / 2, m);
    temp = (temp * temp) % m;
    
    if (n % 2 == 1) {
        temp = (temp * (a % m)) % m;
    }
    
    return temp;
}

int main() {
    int a = 2;
    int n = 100;
    int b = 7;
    
    int result = mod(a, n, b);
    
    cout << "2^100 mod 7 = " << result << endl;
    cout << "2^9 mod 7 = " << mod(2, 9, 7) << endl;
    
    return 0;
}