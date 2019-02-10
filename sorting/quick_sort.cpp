#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void print_vector(const vector<int>& vec);
void quick_sort(vector<int>& vec, int start, int end);

int main()
{
    vector<int> vec{15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};

    cout << "Before sort:\n";
    print_vector(vec);

    quick_sort(vec, 0, vec.size() - 1);

    cout << "After sort:\n";
    print_vector(vec);
}

void print_vector(const vector<int>& vec)
{
    for (auto itr = vec.begin(), end = vec.end(); itr != end; ++itr)
        cout << *itr << ' ';
    cout << "\n\n";
}

void quick_sort(vector<int>& vec, int start, int end)
{
    if (start < end) {
        int left = start;
        int right = end;
        int pivot = vec[(left + right) / 2];

        while (true) {
            while (vec[left] < pivot)
                ++left;
            while (vec[right] > pivot)
                --right;

            if (left >= right)
                break;

            swap(vec[left], vec[right]);
            ++left;
            --right;
        }

        quick_sort(vec, start, left - 1);
        quick_sort(vec, right + 1, end);
    }
}

