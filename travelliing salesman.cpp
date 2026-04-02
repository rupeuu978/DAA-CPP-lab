#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

// Adjacency matrix representing distances between cities
int dist[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int n = 4;
int VISITED_ALL = (1 << n) - 1;
int memo[16][4]; // dp[mask][pos]

int tsp(int mask, int pos) {
    // Base Case: If all cities are visited, return cost to go back to start (city 0)
    if (mask == VISITED_ALL) {
        return dist[pos][0];
    }

    // Return cached result if already calculated
    if (memo[mask][pos] != -1) {
        return memo[mask][pos];
    }

    int ans = INF;

    // Try visiting every city that hasn't been visited yet
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return memo[mask][pos] = ans;
}

int main() {
    // Initialize memo table with -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
        }
    }

    cout << "Minimum Cost: " << tsp(1, 0) << endl; // Start at city 0 (mask 1)
    return 0;
}
