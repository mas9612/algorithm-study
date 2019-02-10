#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void selection_sort_from_max(vector<int>& vec);
void selection_sort_from_min(vector<int>& vec);

int main()
{
    vector<int> vec{15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};

    cout << "Before sort:\n";
    for (auto itr = vec.begin(), end = vec.end(); itr != end; ++itr)
        cout << *itr << ' ';
    cout << '\n';

    selection_sort_from_max(vec);
    // selection_sort_from_min(vec);

    cout << "After sort:\n";
    for (auto itr = vec.begin(), end = vec.end(); itr != end; ++itr)
        cout << *itr << ' ';
    cout << '\n';
}

void selection_sort_from_max(vector<int>& vec)
{
    int size = vec.size();

    for (int i = size - 1; i >= 0; --i) {
        int max_index = i;
        for (int j = 0; j < i; ++j) {
            if (vec[j] > vec[max_index])
                max_index = j;
        }

        swap(vec[i], vec[max_index]);
    }
}

void selection_sort_from_min(vector<int>& vec)
{
    int size = vec.size();

    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (vec[j] < vec[min_index])
                min_index = j;
        }

        swap(vec[i], vec[min_index]);
    }
}
