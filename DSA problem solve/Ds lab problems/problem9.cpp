#include<bits/stdc++.h>
using namespace std;

vector<string> result;
string str = {'a','b','c'};

void addChar(string s, int n){
    if(s.size() == n){
        result.push_back(s);
        return;
    }

    for(char ch : str){
        if(s.empty() || s.back() != ch){
            addChar(s+ch, n);
        }
    }
}

string happyString(int n, int k){
    
    addChar("",n);
    return result[k-1];
}

int main(){
    int n, k;

    cout<< "enter value : k and n =";
    cin>>n;
    cin>>k;

    cout<< happyString(n,k)<<endl;
}