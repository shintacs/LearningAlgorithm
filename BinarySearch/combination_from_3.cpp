#include <iostream>
#include <algorithm>
#include <vector>

int N;

int main()
{
    std::cin >> N;
    std::vector<int> a(N), b(N), c(N);

    for(int i=0; i<N; ++i) std::cin >> a[i];
    for(int i=0; i<N; ++i) std::cin >> b[i];
    for(int i=0; i<N; ++i) std::cin >> c[i];
    
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    int sum = 0;

    for(int i=0; i<N; ++i)
    {
        int A = std::lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int C = c.end() - std::upper_bound(c.begin(), c.end(), b[i]);
        sum += A*C;
    }

    std::cout << sum << std::endl;
}

