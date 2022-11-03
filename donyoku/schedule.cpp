#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using Interval = std::pair<int, int>;

bool comp(const Interval &a, const Interval &b)
{
    return a.second < b.second;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<Interval> v(N);
    for(int i=0; i<N; ++i) std::cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), comp);

    int num = 0;
    int current_time = 0;
    for(int i=0; i<N; ++i)
    {
        if(v[i].first < current_time) continue;
        ++num;
        current_time = v[i].second;
    }
    std::cout << num << std::endl;
}