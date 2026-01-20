#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int idx = 0;

    for (int i = 0; i < n; i++) {
        string sub = s.substr(i);
        if (isPalindrome(sub)) {
            idx = i;
            break;
        }
    }

    string prefix = s.substr(0, idx);
    reverse(prefix.begin(), prefix.end());

    cout << s + prefix << endl;

    return 0;
}