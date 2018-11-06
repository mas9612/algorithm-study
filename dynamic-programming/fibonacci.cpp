#include <ctime>
#include <iostream>

using namespace std;

int fibonacci(int num);
int memoize_fibonacci(int* memo, int num);

int main()
{
    int num;
    cin >> num;

    int result;
    time_t start, end;

    int* memo = new int[num+1];
    for (int i = 0; i < num+1; ++i)
        memo[i] = -1;
    start = time(NULL);
    result = memoize_fibonacci(memo, num);
    end = time(NULL);
    cout << "[Dynamic Programming (Memoize)]\n";
    cout << result << '\n';
    cout << "Elapsed time: " << end - start << "\n\n";

    start = time(NULL);
    result = fibonacci(num);
    end = time(NULL);
    cout << "\n[Simple Recursion]\n";
    cout << result << '\n';
    cout << "Elapsed time: " << end - start << "\n\n";

    delete[] memo;
}

int fibonacci(int num)
{
    if (num <= 0)
        return 0;
    else if (num == 1)
        return 1;

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int memoize_fibonacci(int* memo, int num)
{
    if (num <= 0)
        return 0;
    else if (num == 1)
        return 1;
    else if (memo[num] > 0)
        return memo[num];

    int result = memoize_fibonacci(memo, num - 1) + memoize_fibonacci(memo, num - 2);
    memo[num] = result;
    return result;
}

