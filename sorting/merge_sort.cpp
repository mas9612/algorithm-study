#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> vec);
void merge_sort(vector<int>& vec, int start, int end);
void merge(vector<int>& vec, int start, int end, int mid);

int main()
{
    vector<int> vec{2, 4, 5, 7, 1, 8, 3, 6};

    cout << "Before sort:\n";
    print_vector(vec);

    merge_sort(vec, 0, vec.size() - 1);

    cout << "After sort:\n";
    print_vector(vec);
}

void print_vector(vector<int> vec)
{
    for (auto itr = vec.begin(), end = vec.end(); itr != end; ++itr)
        cout << *itr << ' ';
    cout << '\n';
}

void merge_sort(vector<int>& vec, int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(vec, start, mid);
        merge_sort(vec, mid + 1, end);
        merge(vec, start, end, mid);
    }
}

void merge(vector<int>& vec, int start, int end, int mid)
{
    vector<int> v1(mid - start + 1);
    vector<int> v2(end - (mid + 1) + 1);

    int size1 = v1.size();
    for (int i = 0; i < size1; ++i)
        v1[i] = vec[start + i];

    int size2 = v2.size();
    for (int i = 0; i < size2; ++i)
        v2[i] = vec[mid + 1 + i];

    int idx1 = 0;
    int idx2 = 0;
    int i = start;
    while ((idx1 < size1) && (idx2 < size2)) {
        if (v1[idx1] < v2[idx2]) {
            vec[i] = v1[idx1];
            ++idx1;
            ++i;
        } else {
            vec[i] = v2[idx2];
            ++idx2;
            ++i;
        }
    }

    while (idx1 < size1) {
        vec[i] = v1[idx1];
        ++idx1;
        ++i;
    }

    while (idx2 < size2) {
        vec[i] = v2[idx2];
        ++idx2;
        ++i;
    }
}

