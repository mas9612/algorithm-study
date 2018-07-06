#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void heap_sort(vector<int>& vec);
void build_heap(vector<int>& vec, int size);
void max_heapify(vector<int>& vec, int index, int size);
void print_vector(const vector<int> vec);

int main()
{
    vector<int> vec{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    cout << "Before sort:\n";
    print_vector(vec);

    heap_sort(vec);

    cout << "After sort:\n";
    print_vector(vec);
}

void print_vector(const vector<int> vec)
{
    for (auto itr = vec.begin(), end = vec.end(); itr != end; ++itr)
        cout << *itr << ' ';
    cout << "\n\n";
}

void heap_sort(vector<int>& vec)
{
    for (int i = vec.size() - 1; i > 0; --i) {
        build_heap(vec, i + 1);
        swap(vec[0], vec[i]);
    }
}

void build_heap(vector<int>& vec, int size)
{
    for (int i = size / 2; i >= 0; --i)
        max_heapify(vec, i, size);
}

void max_heapify(vector<int>& vec, int index, int size)
{
    int max_index = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child < size && vec[left_child] > vec[max_index])
        max_index = left_child;

    if (right_child < size && vec[right_child] > vec[max_index])
        max_index = right_child;

    if (max_index != index) {
        swap(vec[index], vec[max_index]);
        max_heapify(vec, max_index, size);
    }
}

