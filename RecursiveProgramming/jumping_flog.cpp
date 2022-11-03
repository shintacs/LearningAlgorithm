#include <iostream>
#include <vector>

int chmin(int N, const std::vector<int> &step)
{
    std::vector<int> cost(N, 100); //大きめの数で初期化
    cost[0] = 0;
    cost[1] = abs(step[1]-step[0]);
    for(int i=2; i<N; ++i)
    {
        if(abs(step[i] - step[i-1]) + cost[i-1] < abs(step[i] - step[i-2]) + cost[i-2])
            cost[i] = abs(step[i-1] - step[i]) + cost[i-1];
        else
            cost[i] = abs(step[i-2] - step[i]) + cost[i-2];
    }

    for(int i=0; i<N; ++i)
    {
        std::cout << cost[i] << std::endl;
    }

    return cost[N-1];
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> step(N);
    for(int i=0; i<N; ++i) std::cin >> step[i];
    std::cout << chmin(N, step) << std::endl;
}