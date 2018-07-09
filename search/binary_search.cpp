#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> vec, int key);

int main()
{
    vector<int> vec{1, 4, 8, 9, 11, 15, 17, 22, 23, 26};

    int key = 23;
    cout << binary_search(vec, key) << '\n';
}

int binary_search(vector<int> vec, int key)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (vec[mid] == key)
            return mid;
        else if (vec[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

