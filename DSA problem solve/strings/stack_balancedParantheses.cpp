#include<bits/stdc++.h>
using namespace std;

bool hasBalancedParentheses(string s){
    stack<char> st;
    for(char c : s){
        if(c == '(' || c== '{' || c== '['){
            st.push(c);
        }else{
            if(st.empty()){
                return false;
            }else if(c == ')' && st.top() == '(' ||
                     c == '}' && st.top() == '{' ||
                     c == ']' && st.top() == '['){
                st.pop();
            }
        }
    }
    return st.empty();
}

int main(){
    string s;
    cout<<"Enter the parentheses string: ";
    cin>>s;
    cout<<"has balanced parentheses: "<<hasBalancedParentheses(s)<<endl;
}