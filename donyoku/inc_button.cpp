#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> a(N), b(N);

    for(int i=0; i<N; ++i) std::cin >> a[i] >> b[i];

    int btn = 0;
    int d = 0;

    for(int i=N-1; i>=0; --i)
    {
        a[i] += btn;
        if(a[i] % b[i] == 0) d = 0;
        else d = b[i] - (a[i] % b[i]);

        btn += d;
    }

    std::cout << btn << std::endl;

}