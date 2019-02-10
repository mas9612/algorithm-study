#include <algorithm>
#include <iostream>

// Heap implements heap data structure.
// In this implementation, index-zero will not be used for convenience.
class Heap {
   public:
    int* data;
    int heap_size;
    int capacity;

    Heap(int size) : heap_size(0), capacity(size) { data = new int[size + 1]; }
    ~Heap() { delete[] data; }

    void insert(int n) {
        if (heap_size + 1 > capacity)
            throw "heap overflow\n";
        ++heap_size;
        data[heap_size] = n;
    }

    void max_heapify(int root) {
        int left = root * 2;
        int right = root * 2 + 1;
        int max_index = root;
        if ((left <= heap_size) && (data[left] > data[max_index]))
            max_index = left;
        if ((right <= heap_size) && (data[right] > data[max_index]))
            max_index = right;

        if (max_index != root) {
            std::swap(data[root], data[max_index]);
            max_heapify(max_index);
        }
    }

    void build_heap() {
        for (int i = heap_size / 2; i > 0; --i)
            max_heapify(i);
    }

    void print_heap() {
        if (heap_size > 0) {
            std::cout << data[1];
            for (int i = 2; i <= heap_size; ++i)
                std::cout << ' ' << data[i];
            std::cout << '\n';
        }
    }
};
