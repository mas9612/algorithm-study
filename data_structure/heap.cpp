#include "heap.h"
#include <iostream>

using namespace std;

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
