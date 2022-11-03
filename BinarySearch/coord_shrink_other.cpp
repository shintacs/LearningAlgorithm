#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    for(int i=0; i<N; ++i) std::cin >> v[i];

    std::vector<int> cv = v; //この書き方知らなかった...numpyみたいに使えるのか

    sort(cv.begin(), cv.end());

    for(int i=0; i<N; ++i)
    {
        std::cout << std::lower_bound(cv.begin(), cv.end(), v[i]) - cv.begin() << " "; //lower_boundが返しているのはイテレータであることを知っていると理解が容易
    }
    std::cout << std::endl;
}