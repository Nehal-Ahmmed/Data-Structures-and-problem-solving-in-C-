#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int caseNum = 1;
    int NC;
    
    while (cin >> NC && NC != 0) {
        vector<pair<int, int>> connections;
        unordered_set<int> nodeSet;
        
        for (int i = 0; i < NC; i++) {
            int a, b;
            cin >> a >> b;
            connections.push_back({a, b});
            nodeSet.insert(a);
            nodeSet.insert(b);
        }
        
        vector<int> nodeList(nodeSet.begin(), nodeSet.end());
        map<int, int> nodeId;
        int V = nodeList.size();
        
        for (int i = 0; i < V; i++) {
            nodeId[nodeList[i]] = i;
        }
        
        vector<int> adj[V];
        for (auto& conn : connections) {
            int u = nodeId[conn.first];
            int v = nodeId[conn.second];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int start, ttl;
        while (cin >> start >> ttl && (start != 0 || ttl != 0)) {
            int unreachable;
            
            if (nodeId.find(start) == nodeId.end()) {
                unreachable = V;
            } else {
                int s = nodeId[start];
                vector<int> dist(V, -1);
                dist[s] = 0;
                
                queue<int> q;
                q.push(s);
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    
                    if (dist[u] >= ttl) continue;
                    
                    for (int v : adj[u]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                }
                
                unreachable = 0;
                for (int d : dist) {
                    if (d == -1 || d > ttl) {
                        unreachable++;
                    }
                }
            }
            
            cout << "Case " << caseNum << ": " << unreachable 
                 << " nodes not reachable from node " << start 
                 << " with TTL = " << ttl << ".\n";
            caseNum++;
        }
    }
    
    return 0;
}