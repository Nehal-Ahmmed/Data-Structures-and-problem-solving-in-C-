#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pos_in_exit(n + 1);
    
    vector<int> enter_order(n);
    for (int i = 0; i < n; i++) {
        cin >> enter_order[i];
    }
    
    for (int i = 0; i < n; i++) {
        int car;
        cin >> car;
        pos_in_exit[car] = i;
    }
    
    vector<bool> fined(n + 1, false);
    int maxExit = -1;
    
    for (int i = 0; i < n; i++) {
        int current_car = enter_order[i];
        int currentExit = pos_in_exit[current_car];
        
        if (currentExit < maxExit) {
            fined[current_car] = true;
        }
        
        if (currentExit > maxExit) {
            maxExit = currentExit;
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (fined[i]) answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}