#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find_max(vector<int> v, int left, int right);

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << "\nMax: " << find_max(v, 0, n-1) << '\n';
}

int find_max(vector<int> v, int left, int right)
{
    if (left >= right)
        return v[left];

    int mid = (right + left) / 2;
    int lans = find_max(v, left, mid);
    int rans = find_max(v, mid+1, right);
    return max(lans, rans);
}

