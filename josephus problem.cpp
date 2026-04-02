#include <iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 1;
    else
        // The +1 converts 0-based result of modulo to 1-based index
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    int n = 7, k = 3;
    cout << "The safe position is: " << josephus(n, k) << endl;
    return 0;
}

