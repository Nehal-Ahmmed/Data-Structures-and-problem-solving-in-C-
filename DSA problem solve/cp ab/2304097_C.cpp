#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> create_lps(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int comparing() {
    string text, pattern;
    if (!(cin >> text >> pattern)) return -1;
    vector<int> lps = create_lps(pattern);
    int n = text.length();
    int m = pattern.length();
    int i = 0; 
    int j = 0; 
    int max_len = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
            max_len = max(max_len, j);
            if (j == m) break; 
        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return max_len;
}

int main() {
    int result;
    while (true) {
        result = comparing();
        if (result == -1) break;
        cout<<"the output of the Kmp matching solution is: ";
        cout<< result << endl;
    }
    return 0;
}