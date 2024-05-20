#include "threadpool.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    thread_pool pool;

    // Using the parallel_for_each API, the function receives the the index of the element to be processed
    pool.parallel_for_each<long>(0, v.size(), [&](int i, size_t _thread_idx) { v[i] += 1; });
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';

    // Using the parallel_for API, the function receives the range of the elements to be processed
    pool.parallel_for<long>(0, v.size(), [&](blocked_range<long> range, size_t _thread_idx) {
        for (long i = range.first; i < range.second; i++)
            v[i] += 1;
    });
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
