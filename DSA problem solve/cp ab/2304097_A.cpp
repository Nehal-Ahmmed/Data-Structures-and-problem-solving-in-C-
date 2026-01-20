#include <iostream>
#include <vector>

using namespace std;

void findingperfectnumbers(int n) {
    vector<int> sumDivisors(n + 1, 1);
    sumDivisors[0] = 0;
    sumDivisors[1] = 0;

    for (int i = 2; i <= n / 2; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            sumDivisors[j] += i;
        }
    }

    bool first = true;
    for (int i = 2; i <= n; ++i) {
        if (sumDivisors[i] == i) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout<<"Enter the Number (in the loop): "<<endl;
    while (cin >> n) {
        findingperfectnumbers(n);
    }
    return 0;
}