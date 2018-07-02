#include <iostream>
#include <vector>

using namespace std;

int sequenatial_search(vector<int> vec, int key);

int main()
{
    vector<int> vec{1, 4, 8, 9, 11, 15, 17, 22, 23, 26};

    int key;
    cout << "search key: ";
    cin >> key;

    int pos = sequenatial_search(vec, key);
    if (pos != -1)
        cout << key << " found at index " << pos << '\n';
    else
        cout << key << " not found\n";
}

int sequenatial_search(vector<int> vec, int key)
{
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == key)
            return i;
    }

    return -1;
}

