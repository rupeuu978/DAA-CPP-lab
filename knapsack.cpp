#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0-1 Knapsack using Space-Optimized Dynamic Programming
int knapSack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // dp[w] stores the maximum value for a knapsack of capacity w
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // Iterate backwards to ensure each item is used only once
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    return dp[W];
}

int main() {
    int W = 50; // Max capacity
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int n = values.size();

    cout << "Maximum value in Knapsack: " << knapSack(W, weights, values, n) << endl;

    return 0;
}
