#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cout<<"Enter the string: ";
    cin>>s;
    n=s.length();

    int carry =1; 

    
    for (int i = n - 1; i >= 0 && carry > 0; i--) {
        int digit = s[i] - '0';
        digit += carry;
        carry = digit / 10;
        digit %= 10;
        s[i] = digit + '0';
    }
    
    if (carry > 0) {
        s = "1" + s;
    }
    

    cout<<"Result string is: ";
    cout<<s<<endl;
}