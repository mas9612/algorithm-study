#include <algorithm>
#include <iostream>
#include "heap.h"

using namespace std;

class MaxPriorityQueue : public Heap {
   public:
    MaxPriorityQueue(int size) : Heap(size) {}

    int maximum() {
        if (heap_size > 0)
            return data[1];
        return -1;
    }

    int extract_max() {
        if (heap_size > 0) {
            int ret = maximum();
            data[1] = data[heap_size];
            --heap_size;
            max_heapify(1);
            return ret;
        }
        return -1;
    }

    void increase_key(int index, int new_val) {
        if (data[index] > new_val)
            return;

        data[index] = new_val;

        int parent = index / 2;
        while (data[parent] < data[index]) {
            swap(data[parent], data[index]);
            index = parent;
            parent = index / 2;
        }
    }
};

int main() {
    int n;
    cout << "queue size: ";
    cin >> n;

    MaxPriorityQueue m(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        m.insert(tmp);
    }
    m.build_heap();

    cout << "\ninitial state:\n";
    m.print_heap();

    int index, value;
    cout << "\nincrease (index, value): ";
    cin >> index >> value;
    m.increase_key(index, value);

    cout << "\nafter increase:\n";
    m.print_heap();

    cout << "\nmax: " << m.maximum() << '\n';

    m.extract_max();
    cout << "\nafter extract max:\n";
    m.print_heap();
}
