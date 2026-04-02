#include <iostream>
#include <vector>
#include <numeric>

// Function to "weigh" a range of coins in the array
int weigh(const std::vector<int>& coins, int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += coins[i];
    }
    return sum;
}

// Recursive function to find the index of the lighter fake coin
int findFakeCoin(const std::vector<int>& coins, int left, int right) {
    // Base case: only one coin left
    if (left == right) {
        return left;
    }

    int n = right - left + 1;
    int groupSize = n / 3;
    
    // Divide into 3 groups: [A], [B], and [C]
    // Group A: left to left + groupSize - 1
    // Group B: left + groupSize to left + 2*groupSize - 1
    // Group C: left + 2*groupSize to right
    
    int endA = left + groupSize - 1;
    int startB = left + groupSize;
    int endB = left + 2 * groupSize - 1;
    int startC = left + 2 * groupSize;

    int weightA = weigh(coins, left, endA);
    int weightB = weigh(coins, startB, endB);

    if (weightA < weightB) {
        // Fake is in Group A
        return findFakeCoin(coins, left, endA);
    } else if (weightA > weightB) {
        // Fake is in Group B
        return findFakeCoin(coins, startB, endB);
    } else {
        // weightA == weightB, so fake must be in Group C
        return findFakeCoin(coins, startC, right);
    }
}

int main() {
    // 1 represents a real coin, 0 represents the lighter fake coin
    std::vector<int> coins = {1, 1, 1, 1, 0, 1, 1, 1, 1}; 
    int n = coins.size();

    int fakeIndex = findFakeCoin(coins, 0, n - 1);
    
    std::cout << "The fake coin is at index: " << fakeIndex << std::endl;
    return 0;
}
