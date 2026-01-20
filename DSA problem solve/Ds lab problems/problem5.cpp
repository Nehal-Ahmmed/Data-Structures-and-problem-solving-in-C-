#include <iostream>
using namespace std;

void addD(int arr[], int n, int D) {
    cout << "SD" << endl;
    for (int i = 0; i < n; ++i) arr[i] += D;
}

void mulD(int arr[], int n, int D) {
    cout << "MD" << endl;
    for (int i = 0; i < n; ++i) arr[i] *= D;
}

void divK(int arr[], int n, int K) {
    cout << "DK" << endl;
    if (K == 0) {
        cout << "Cannot divide by zero" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) arr[i] /= K; 
}

void swapYZ(int arr[], int n, int Y, int Z) {
    cout << "PYZ" << endl;
    int temp = arr[Y];
    arr[Y] = arr[Z];
    arr[Z] = temp;
}

void reverseArr(int arr[], int n) {
    cout << "R" << endl;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void display(const int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int D = 5;
    int K = 2;

    addD(arr, n, D);
    display(arr, n);

    mulD(arr, n, D);
    display(arr, n);

    divK(arr, n, K);
    display(arr, n);

    swapYZ(arr, n, 2, 3); 
    display(arr, n);

    reverseArr(arr, n);
    display(arr, n);

    return 0;
}
