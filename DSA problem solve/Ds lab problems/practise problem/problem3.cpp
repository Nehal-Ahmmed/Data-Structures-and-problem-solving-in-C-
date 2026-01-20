#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addOne(string num) {
    int n = num.length();
    int carry = 1; // We are adding 1
    
    for (int i = n - 1; i >= 0 && carry > 0; i--) {
        int digit = num[i] - '0';
        digit += carry;
        carry = digit / 10;
        digit %= 10;
        num[i] = digit + '0';
    }
    
    // If carry remains, insert 1 at the beginning
    if (carry > 0) {
        num = "1" + num;
    }
    
    return num;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string N;
        cin >> N;
        cout << addOne(N) << endl;
    }
    
    return 0;
}