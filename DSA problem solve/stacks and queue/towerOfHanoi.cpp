// tower_hanoi.cpp
#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char Rod_A, char Rod_c, char Rod_B, int &step) {
    if (n == 1) {
        cout << "Step " << ++step << ": Move disk 1 :: " << Rod_A << " -> " << Rod_c << endl;
        return;
    }
    
    towerOfHanoi(n - 1, Rod_A, Rod_B, Rod_c, step);
    cout << "Step " << ++step << ": Move disk " << n << " :: " << Rod_A << " -> " << Rod_c << endl;
    towerOfHanoi(n - 1, Rod_B, Rod_c, Rod_A, step);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Please enter a positive number!" << endl;
        return 0;
    }
    
    cout << " **~~Tower of Hanoi Solution : " << endl;
    cout << "Moving " << n << " disks from rod A to rod C using rod B" << endl;
    
    int step = 0;
    towerOfHanoi(n, 'A', 'C', 'B', step);
    
    cout <<"info: \n"<< endl;
    cout << "Total steps required: " << step << endl;
    
    return 0;
}