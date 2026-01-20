#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cout<<"Enter number of test cases: ";
    cin>>T;

    double arr[T];
    int index=0;

    while (T--)
    {
        int x,totalPrize=0;
        cout<<"Enter the amount X: ";
        cin>>x;
        totalPrize= x*100;

        int Chefscores=0, CarlsenScores=0;
        string s;
        cout<<"Enter the String consist of C N D containing 14 characters: ";
        cin>>s;

        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='C'){
                Chefscores+=2;
            }
            else if(s[i]=='N'){
                CarlsenScores+=2;
            }
            else{
                Chefscores+=1;
                CarlsenScores+=1;
            }
        }
        
        if(Chefscores>CarlsenScores){
            arr[index]= totalPrize*0.6;
            index++;
        }else if(CarlsenScores>Chefscores){
            arr[index]= totalPrize*0.4;
            index++;
        }else{
            arr[index]= totalPrize*0.55;
            index++;
        }
        
    }

    cout<<"The Prize amounts are: "<<endl;
    for(int n: arr){
        cout<<fixed<<setprecision(6)<<n<<endl;
    }
    
}