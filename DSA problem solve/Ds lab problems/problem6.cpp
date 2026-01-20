#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cout<<"Enter number of test cases: ";
    cin>>T;
    double carlsenPrize[T];
    int j= 0;

    while(T--){
        int X;
        cout<<"Enter the value X: ";
        cin>>X;
        int totalPrize = X*100;
        string s;
        cout<<"enter the string consisting of CND (length must be 14) :";
        cin>>s;

        int cheffScore = 0;
        int carlenscore = 0;

        for(int i=0; i<s.size() ; i++){
            if(s[i]=='C'){
                carlenscore+=2;
            }
            else if(s[i]=='N'){
                cheffScore+=2;
            }
            else{
                cheffScore+=1;
                carlenscore+=1;
            }
        }

        if(carlenscore>cheffScore){
            carlsenPrize[j] = totalPrize*0.6;
            j++;
        }else if(cheffScore>carlenscore){
            carlsenPrize[j] = totalPrize*0.4;
            j++;
        }else{
            carlsenPrize[j] = totalPrize*0.55;
            j++;
        }
    }

    cout<<"carlsen prizes are : "<<endl;
    for(double a: carlsenPrize){
        cout<<a<<endl;
    }
}