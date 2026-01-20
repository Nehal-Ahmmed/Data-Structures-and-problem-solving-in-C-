#include<bits/stdc++.h>
using namespace std;

vector<string> result;

void addChar(string curr,int n){

    if(curr.size() == n){
        result.push_back(curr);
        return;
    }

    for(char ch : {'a','b','c'}){
        if(curr.empty() || curr.back() != ch){
            addChar(curr+ch, n);
        }
    }
}

string getHappyString(int n, int k){
    addChar("",n);
    if(k>result.size()){
        return "";
    }
    return result[k-1];
}

int main(){
cout << "n=1, k=3: " << getHappyString(1, 3) << endl;  // "c"
    cout << "n=1, k=4: " << getHappyString(1, 4) << endl;  // ""
    cout << "n=3, k=9: " << getHappyString(3, 9) << endl;
}