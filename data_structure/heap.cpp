#include <algorithm>
#include <iostream>

using namespace std;

// Heap implements heap data structure.
// In this implementation, index-zero will not be used for convenience.
class Heap {
    int* data;
    int heap_size;
    int capacity;

   public:
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
            swap(data[root], data[max_index]);
            max_heapify(max_index);
        }
    }

    void build_heap() {
        for (int i = heap_size / 2; i > 0; --i)
            max_heapify(i);
    }

    void print_heap() {
        if (heap_size > 0) {
            cout << data[1];
            for (int i = 2; i <= heap_size; ++i)
                cout << ' ' << data[i];
            cout << '\n';
        }
    }
};

int main() {
    int n;
    cout << "heap size: ";
    cin >> n;

    Heap h(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        h.insert(tmp);
    }

    cout << "\nbefore heapify:\n";
    h.print_heap();

    h.build_heap();
    cout << "\nafter heapify:\n";
    h.print_heap();
}
