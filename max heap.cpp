#include <iostream>
#include <vector>
#include <algorithm>

class MaxHeap {
private:
    std::vector<int> heap;

    // Returns parent, left child, and right child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Maintain max heap property from top to bottom
    void heapifyDown(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Maintain max heap property from bottom to top
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    void push(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    bool empty() { return heap.empty(); }
};

int main() {
    MaxHeap mh;
    mh.push(10); mh.push(30); mh.push(20); mh.push(5);
    
    std::cout << "Max element: " << mh.top() << std::endl; // Output: 30
    mh.pop();
    std::cout << "Next max element: " << mh.top() << std::endl; // Output: 20
    return 0;
}
