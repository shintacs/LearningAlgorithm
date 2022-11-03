#include <iostream>
#include <vector>
const long long INF = 1LL << 60;

std::vector<int> step;
std::vector<long long> tbl;

template<class T> void chmin(T& a, T b)
{
    if(a > b) a = b;
}

long long cost(int i)
{
    if(tbl[i] < INF) return tbl[i];

    if(i == 0) return tbl[i] = 0;

    long long res = INF;
    chmin(res, cost(i-1) + abs(step[i]-step[i-1]));
    if(i > 1) chmin(res, cost(i-2) + abs(step[i]-step[i-2]));

    return tbl[i] = res;
}

int main()
{
    //入力
    int N;
    std::cin >> N;
    step.resize(N);
    for(int i=0; i<N; ++i) std::cin >> step[i];
    tbl.assign(N,INF);

    std::cout << cost(N-1) << std::endl;
}