#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        int min_idx = i;
        
        // Check the rest of the array for a smaller element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    vector<int> data = {64, 25, 12, 22, 11};
    
    selectionSort(data);
    
    cout << "Sorted array: ";
    for (int val : data) cout << val << " ";
    
    return 0;
}
