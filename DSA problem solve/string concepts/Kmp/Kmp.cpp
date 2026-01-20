#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> buildLPS(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int length = 0; 
    for (int i = 1; i < m; i++) {
        while (length > 0 && pattern[i] != pattern[length]) {
            length = lps[length - 1];
        }
        if (pattern[i] == pattern[length]) {
            length++;
        }
        lps[i] = length;
    }
    return lps;
}

vector<int> KMPSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> occurrences;

    if (m == 0) return occurrences;

    vector<int> lps = buildLPS(pattern);
    int j = 0; 

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            occurrences.push_back(i - m + 2); 
            j = lps[j - 1]; 
        }
    }
    return occurrences;
}


int main() {
    int T;
    cout << "--- KMP Pattern Searching ---" << endl;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        string text, pattern;
        
        cout << "\n----------------------------" << endl;
        cout << "Enter the Main String (Text): ";
        cin >> text;
        cout << "Enter the Substring (Pattern) to find: ";
        cin >> pattern;

        vector<int> result = KMPSearch(text, pattern);

        if (result.empty()) {
            cout << "\nResult: Not Found" << endl;
        } else {
            cout << "\nResult: Found " << result.size() << " occurrence(s)!" << endl;
            cout << "Pattern found at positions: ";
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << (i == result.size() - 1 ? "" : ", ");
            }
            cout << endl;
        }
    }

    cout << "\n--- Process Completed ---" << endl;
    return 0;
}