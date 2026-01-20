#include <iostream>
using namespace std;

// Function to find first occurrence of target
int firstOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Search left for earlier occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

// Function to find last occurrence of target
int lastOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Search right for later occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

// Function to count occurrences of target
int countOccurrences(int arr[], int n, int target) {
    int first = firstOccurrence(arr, n, target);
    if (first == -1) return 0; // Target not found
    int last = lastOccurrence(arr, n, target);
    return last - first + 1;
}

// Main function
int main() {
    int n, target;
    
    // Get array size from user
    cout << "Enter the size of the sorted array: ";
    cin >> n;
    
    int arr[n];
    
    cout << "Enter " << n << " sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the target value to count: ";
    cin >> target;
    
    int count = countOccurrences(arr, n, target);
    
    if (count > 0) {
        int first = firstOccurrence(arr, n, target);
        int last = lastOccurrence(arr, n, target);
        
        cout << "\nResults:\n";
        cout << "First occurrence at index: " << first << endl;
        cout << "Last occurrence at index: " << last << endl;
        cout << "Total occurrences: " << count << endl;
        
        cout << "\nThe given Array :\n";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "\nTarget " << target << " not found in the array.\n";
    }
  
}