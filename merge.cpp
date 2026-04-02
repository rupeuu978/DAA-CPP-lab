#include <iostream>
#include <vector>
#include <algorithm> // Required for std::merge

int main() {
    std::vector<int> v1 = {1, 3, 5, 7};
    std::vector<int> v2 = {2, 4, 6, 8};
    std::vector<int> destination(v1.size() + v2.size());

    // Merges v1 and v2 into 'destination'
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), destination.begin());

    for (int x : destination) std::cout << x << " "; 
    return 0;
}
