#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while (cin >> n && n != 0) {
        int l;
        cin >> l;
        
        vector<int> adj[200];
        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int color[200];
        memset(color, -1, sizeof(color));
        bool bicolorable = true;
        
        for (int start = 0; start < n && bicolorable; start++) {
            if (color[start] != -1) continue;
            
            queue<int> q;
            q.push(start);
            color[start] = 0;
            
            while (!q.empty() && bicolorable) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        bicolorable = false;
                        break;
                    }
                }
            }
        }
        
        if (bicolorable) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }
    
    return 0;
}