#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> children_count(n + 1, 0);
        
        for (int i = 2; i <= n; i++) {
            int parent;
            std::cin >> parent;
            children_count[parent]++;
        }
        
        std::vector<int> groups;
        
        for (int i = 1; i <= n; i++) {
            if (children_count[i] > 0) {
                groups.push_back(children_count[i]);
            }
        }
        
        std::sort(groups.begin(), groups.end(), std::greater<int>());
        
        int time = groups.size() + 1;
        
        std::priority_queue<int> heap;
        
        for (int i = 0; i < groups.size(); i++) {
            int remaining = groups[i] - (groups.size() - i);
            if (remaining > 0) {
                heap.push(remaining);
            }
        }
        
        int extra = 0;
        while (!heap.empty()) {
            int top = heap.top();
            heap.pop();
            
            if (top > extra) {
                extra++;
                if (top - 1 > extra) {
                    heap.push(top - 1);
                }
            }
        }
        
        time += extra;
        
        std::cout << time << std::endl;
    }
    
    return 0;
}