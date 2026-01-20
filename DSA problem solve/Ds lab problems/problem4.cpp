 #include<bits/stdc++.h>
using namespace std;

int main(){
    int N=5,BothHappy=0;
    int Alice[N]={200,300,400,500,1200};
    int Bob[N] = {100, 500, 150, 700, 500};

    for(int i=0; i<N; i++){
    if(Alice[i]*2 >= Bob[i]){
        if(Bob[i]*2 >= Alice[i])
        BothHappy++;
    }
}

cout<<"Both are happy for: "<<BothHappy<<" days";
}