#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& vec);

int main()
{
    vector<int> vec{15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};

    cout << "Before sort\n";
    for (auto itr = vec.begin(), end = vec.end(); itr != end; ++itr)
        cout << *itr << ' ';
    cout << "\n\n";

    insertion_sort(vec);

    cout << "After sort\n";
    for (auto itr = vec.begin(), end = vec.end(); itr != end; ++itr)
        cout << *itr << ' ';
    cout << "\n\n";
}

void insertion_sort(vector<int>& vec)
{
    int size = vec.size();

    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            if (vec[j - 1] > vec[j])
                swap(vec[j - 1], vec[j]);
        }
    }
}

