#include <iostream>
#include <algorithm>
#include <vector>

int binary_search(int N, int key, std::vector<int>& cv)
{
    int left = 0, right = N-1;
    while(right >= left)
    {
        int mid = left + (right - left) / 2;
        if(cv[mid] == key) return mid;
        else if(cv[mid] < key) left = mid + 1;
        else if(cv[mid] > key) right = mid - 1;
    }
    return -1;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    std::vector<int> cv(N);
    for(int i=0; i<N; ++i) std::cin >> v[i];
    for(int i=0; i<N; ++i) cv[i] = v[i];

    sort(cv.begin(), cv.end());
    for(int i=0; i<N; ++i) std::cout << binary_search(N, v[i], cv) << std::endl;
}