#include <iostream>
#include <vector>
const long long INF = 1LL << 60;

int main()
{
    //入力
    int N;
    std::cin >> N;
    std::vector<int> step(N);
    for(int i=0; i<N; ++i) std::cin >> step[i];

    std::vector<long long> tbl(N,INF);

    tbl[0] = 0;
    for(int i=1; i<N; ++i)
    {
        if(i==1) tbl[i] = abs(step[i]-step[i-1]);
        else tbl[i] = std::min(tbl[i-1] + abs(step[i]-step[i-1]), tbl[i-2] + abs(step[i]-step[i-2]));
    }

    std::cout << tbl[N-1] << std::endl;

}