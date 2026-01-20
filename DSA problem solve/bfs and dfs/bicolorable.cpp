#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int start) {
    vector<int> color(graph.size(), -1);
    queue<int> q;
    
    color[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int neighbor : graph[current]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[current];
                q.push(neighbor);
            } else if (color[neighbor] == color[current]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int vertices = 4;
    vector<vector<int>> graph(vertices);
    
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(0);
    graph[3].push_back(2);
    
    if (isBipartite(graph, 0)) {
        cout << "Graph is bipartite (bi-colorable)" << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }
    
    return 0;
}