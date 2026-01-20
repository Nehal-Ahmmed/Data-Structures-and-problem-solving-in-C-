#include<bits/stdc++.h>
using namespace std;

int n = 5;
int adj[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,1,1},
    {0,1,1,0,1},
    {0,0,1,1,0}
};

int visited[5];


void BFS(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=0;i<n;i++){
            if(adj[node][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start){
    stack<int> st;
    st.push(start);

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(visited[node] == 0){
            cout << node << " ";
            visited[node] = 1;
        }

        for(int i=n-1;i>=0;i--){
            if(adj[node][i] == 1 && visited[i] == 0){
                st.push(i);
            }
        }
    }
}

int main(){
    for(int i=0; i<n; i++){
        visited[i]= 0;
    }
    cout << "BFS traversal : ";
    BFS(0);

    for(int i=0; i<n; i++){
        visited[i]= 0;
    }
    cout << "\nDFS traversal : ";
    dfs(0);
    return 0;
}