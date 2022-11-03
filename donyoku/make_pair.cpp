#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N; std::cin >> N;
    std::vector<int> a(N), b(N);
    for(int i=0; i<N; ++i) std::cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;
    for(int i=0; i<N; ++i)
    {
        sum += N - (std::upper_bound(b.begin(), b.end(), a[i])-b.begin());
    }
    std::cout << sum << std::endl;
}