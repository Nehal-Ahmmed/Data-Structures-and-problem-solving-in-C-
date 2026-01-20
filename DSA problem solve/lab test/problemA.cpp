#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (v[i+1].size() >= v[i].size() && v[i+1].substr(0, v[i].size()) == v[i]) {
            ok = false;
            break;
        }
    }
    cout << "Case " << t << ": " << (ok ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}